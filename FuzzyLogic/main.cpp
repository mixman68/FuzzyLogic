#include <iostream>
#include "expr.h"
#include "operator.h"

#include "fuzzy/is.h"
#include "fuzzy/isTriangle.h"
#include "fuzzy/isGaussian.h"

#include "core/FuzzyFactory.h"

using namespace std;
using namespace core;
using namespace fuzzy;

void tests()
{
    cout << "Test Valuemodel" << endl;
    float f1,f2;
    f1=0.8;
    f2=0.12;
    core::ValueModel<float> *vm1 = new core::ValueModel<float>(f1);
    core::ValueModel<float> *vm2 = new core::ValueModel<float>(f2);
    cout << vm1->Evaluate() << endl;
    cout << vm2->Evaluate() << endl;

    AndMin<float>* andmin = new AndMin<float>();
    BinaryExpressionModel<float> a(andmin, vm1, vm2);
	cout << a.Evaluate() << endl;

	AndMult<float>* andmult = new AndMult<float>();
    BinaryExpressionModel<float> b(andmult, vm1, vm2);
	cout << b.Evaluate() << endl;

	AggMax<float>* aggmax = new AggMax<float>();
    BinaryExpressionModel<float> c(aggmax, vm1, vm2);
	cout << c.Evaluate() << endl;

	AggPlus<float>* aggplus = new AggPlus<float>();
    BinaryExpressionModel<float> d(aggplus, vm1, vm2);
	cout << d.Evaluate() << endl;

	NotMinus1<float>* notminus1 = new NotMinus1<float>();
    UnaryExpressionModel<float> e(notminus1, vm1);
	cout << e.Evaluate() << endl;

	OrMax<float>* ormax = new OrMax<float>();
    BinaryExpressionModel<float> f(ormax, vm1, vm2);
	cout << f.Evaluate() << endl;

	OrPlus<float>* orplus = new OrPlus<float>();
    BinaryExpressionModel<float> g(orplus, vm1, vm2);
	cout << g.Evaluate() << endl;

    ThenMin<float>* thenmin = new ThenMin<float>();
    BinaryExpressionModel<float> h(thenmin, vm1, vm2);
	cout << h.Evaluate() << endl;

	ThenMult<float>* thenplus = new ThenMult<float>();
    BinaryExpressionModel<float> i(thenplus, vm1, vm2);
	cout << i.Evaluate() << endl;

	float min,med,max;
	min = 0;
	med = 0.5;
	max = 1;

	isTriangle<float>* istriangle = new isTriangle<float>(min,med,max);
	cout << istriangle->Evaluate(vm1) << endl;

	cout << "Fin des tests primitifs" << endl << endl;
}

void testExempleSimplifie()
{
        cout << "Mamdani defuzz" << endl;



//ai pas fzai les aure sdu coup toit est triangle

    isTriangle<double> poor(-5.0,0.0,5.0);//gaussien
    isTriangle<double> good(0.0,5.0,10.0);//gaussien
    isTriangle<double> excellent(5.0,10.0,15.0);//gaussien
    isTriangle<double> rancid(-5.0,0.0,5.0); //trapeze
    isTriangle<double> delicious(5.0,10.0,15.0); // trapeze

    isTriangle<double> average(10.0,15.0,20.0);
	isTriangle<double> generous(20.0,25.0,30.0);
	isTriangle<double> cheap(0.0,5.0,10.0);

	//Definitin des operateurs !

	NotMinus1<double> opNot;
	AndMin<double> opAnd;
	OrMax<double> opOr;
	AggMax<double> opAgg;
	ThenMin<double> opThen;
	CogDefuzz<double> opDefuzz(0.0,30.0,1.0);


	// HOp on coefficiente un peu

	ValueModel<double> service(8.0);
	ValueModel<double> food(2.0);
	ValueModel<double> tips(0.0);

	//On cre la factory

    FuzzyFactory<double> f(&opNot,&opAnd,&opOr,&opAgg,&opThen,&opDefuzz);

    //Calcul
    core::Expression<double> *res =
    f.NewAgg(
        f.NewAgg(
            f.NewThen(
                f.NewIs(&poor,&service),
                f.NewIs(&cheap,&tips)
            ),
            f.NewThen(
                f.NewIs(&good,&service),
                f.NewIs(&average,&tips)
            )
        ),
        f.NewThen(
            f.NewIs(&excellent,&service),
            f.NewIs(&generous,&tips)
        )
    );

    core::Expression<double> *defuzz = f.NewMamdani(&tips, res);

    cout << "Test exemple reultat :" << defuzz->Evaluate() << endl;
}

int main()
{
    cout << "Hello world!" << endl;
    tests();
    testExempleSimplifie();
    return 0;
}

