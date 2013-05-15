#ifndef ISGAUSSIAN_H
#define ISGAUSSIAN_H

#include "is.h"
#include <math.h>

namespace fuzzy
{
    template <class T>
    class isGaussian: public is<T>
    {
        public:
            virtual T Evaluate(Expression<T>*) const;
        isGaussian(T&, T&);
        protected:
        private:
            T mu, sigma;
    };

    template <class T>
    isGaussian<T>::isGaussian(T& _sigma, T& _mu)  : sigma(_sigma), mu(_mu)
    {}

    template <class T>
    T isGaussian<T>::Evaluate(Expression<T>* _operand) const
    {
        T operand = _operand->Evaluate();
        T result;

        T c = (operand-this->mu)/this->sigma;

        result = exp(-0.5*c*c);

        return result;



    }
}

#endif // ISGAUSSIAN_H
