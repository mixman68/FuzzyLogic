#ifndef SUGENODEFUZZ_H
#define SUGENODEFUZZ_H

#include "../core/NaryExpression.h"
#include "../expr.h"

#include "SugenoThen.h"

using namespace core;

namespace fuzzy
{
template <class T>
class SugenoDefuzz: public NaryExpression<T>
{
public:
    SugenoDefuzz(){};
    virtual T Evaluate(std::vector<Expression<T>*>*) const;
protected:
private:
};

template <class T>
T SugenoDefuzz<T>::Evaluate(std::vector<Expression<T>*>* operands) const
{
    typename std::vector<Expression<T>*>::const_iterator oItr ;
    T num = 0;
    T denum = 0;

    //on evalue tous les operandes

    for(oItr=operands->begin(); oItr!=operands->end(); ++oItr)
    {
        BinaryExpressionModel<T> *operand = (BinaryExpressionModel<T>*) (*oItr);
        //onprend osn operateur
        BinaryShadowExpression<T> *operateur = (BinaryShadowExpression<T>*) operand->GetOperateur();

        //Numérateur
        num+=operand->Evaluate();

        //Dénominateur

        SugenoThen<T> *then = (SugenoThen<T>*) operateur->GetTarget();

        denum += then->GetPremiseValue();
    }

    if(denum==0)
        return 0;

    T tmp = num/denum;

    return tmp;
}
}

#endif // SUGENODEFUZZ_H
