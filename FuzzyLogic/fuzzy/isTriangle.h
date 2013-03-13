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
        protected:
        private:
    };

    template <class T>
    T isTriangle<T>::Evaluate(Expression<T>* _operand) const
    {
        T operand = _operand->Evaluate();

    }
}
#endif // ISTRIANGLE_H
