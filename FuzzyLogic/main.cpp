#include <iostream>
#include "expr.h"
#include "operator.h"

#include "fuzzy/is.h"
#include "fuzzy/isTriangle.h"

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



}

int main()
{
    cout << "Hello world!" << endl;
    tests();
    return 0;
}

