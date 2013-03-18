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
        isTriangle(T& tMin, T& tMid,T& tMax);
        protected:
        private:
            T triangleMin, triangleMid, triangleMax;
    };
    
    template <class T>
    isTriangle<T>::isTriangle(T& tMin, T& tMid,T& tMax)  : triangleMin(tMin), triangleMid(tMid), triangleMax(tMax)
    {}

    template <class T>
    T isTriangle<T>::Evaluate(Expression<T>* _operand) const
    {
        T operand = _operand->Evaluate();
        return operand;
        //TODO

    }
}
#endif // ISTRIANGLE_H
