#ifndef SUGENOTHEN_H
#define SUGENOTHEN_H

#include "Then.h"

namespace fuzzy
{
template<class T>
class SugenoThen: public Then<T>
{
public:
    SugenoThen();
    virtual ~SugenoThen() {};

    virtual T Evaluate(Expression<T>*,Expression<T>*) const;

    virtual T GetPremiseValue() const;
protected:
private:
    mutable T premiseValue;
};

template<class T>
SugenoThen<T>::SugenoThen(): premiseValue(0)
{
}

template<class T>
T SugenoThen<T>::GetPremiseValue() const
{
    return premiseValue;
}

template<class T>
T SugenoThen<T>::Evaluate(core::Expression<T>* left, core::Expression<T>* right) const
{
    premiseValue = left->Evaluate();
    T tmp = premiseValue * right->Evaluate();

    return tmp;
}
}


#endif // SUGENOTHEN_H
