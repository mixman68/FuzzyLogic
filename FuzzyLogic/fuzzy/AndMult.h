#ifndef ANDMULT_H
#define ANDMULT_H


#include "And.h"

namespace fuzzy
{
    template <class T>
    class AndMult: public And<T>
    {
        public:
            virtual T Evaluate(Expression<T>*,Expression<T>*) const;
        protected:
        private:
    };

    template <class T>
    T AndMult<T>::Evaluate(Expression<T>* left, Expression<T>* right) const
    {
        T l = left->Evaluate();
        T r = right->Evaluate();

    }
}

#endif // ANDMULT_H
