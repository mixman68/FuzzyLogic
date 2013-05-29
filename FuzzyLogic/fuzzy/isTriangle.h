#ifndef ISTRIANGLE_H
#define ISTRIANGLE_H

#include "is.h"

namespace fuzzy
{
    template <class T>
    class isTriangle: public is<T>
    {
        public:
            virtual T Evaluate(Expression<T>*) const;
        isTriangle(T, T,T);
        protected:
        private:
            T min, med, max;
    };

    template <class T>
    isTriangle<T>::isTriangle(T tMin, T tMid,T tMax)  : min(tMin), med(tMid), max(tMax)
    {}

    template <class T>
    T isTriangle<T>::Evaluate(Expression<T>* _operand) const
    {
        T operand = _operand->Evaluate();
        T result;

        if(operand<=min || operand >=max)
            return 0;

        if (operand<=med)
            result = (operand - min)/(med-min);
        else if (operand>med)
            result = (max - operand)/(max-med);

        return result;



    }
}
#endif // ISTRIANGLE_H
