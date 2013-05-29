#ifndef NOTMINUS1_H
#define NOTMINUS1_H

#include "Not.h"

namespace fuzzy
{
    template <class T>
    class NotMinus1: public Not<T>
    {
        public:
            virtual T Evaluate(Expression<T>*) const;
        protected:
        private:
    };

    template <class T>
    T NotMinus1<T>::Evaluate(Expression<T>* _operand) const
    {
        T operand = _operand->Evaluate();
        return 1 - operand;

    }
}

#endif // NOTMINUS1_H
