#ifndef ISTRAPEZE_H
#define ISTRAPEZE_H

#include "is.h"

namespace fuzzy
{
template <class T>
class isTrapeze: public is<T>
{
public:
    virtual T Evaluate(Expression<T>*) const;
    isTrapeze(T, T, T, T);
protected:
private:
    T min, mMin, mMax, max;
};

template <class T>
isTrapeze<T>::isTrapeze(T _min, T _mMin, T _mMax, T _max)  : min(_min),mMin(_mMin),mMax(_mMax),max(_max)
{}

template <class T>
T isTrapeze<T>::Evaluate(Expression<T>* _operand) const
{
    T operand = _operand->Evaluate();
    T result;

    if (operand <= this->min || operand >= this->max)
        result = 0 ;
    else if (operand >= this->mMin && operand <= this->mMax)
        result = 1 ;
    else if(operand >= this->min && operand <= this->mMin)
        result = (operand - this->min)/(this->mid1 - this->min);
    else
        result = (this->max - operand)/(this->max - this->mMax);

    return result;



}
}
#endif // ISTRAPEZE_H
