#ifndef ANDMIN_H
#define ANDMIN_H

#include "And.h"

namespace fuzzy
{
    template <class T>
    class AndMin: public And<T>
    {
        public:
            virtual T Evaluate(Expression<T>*,Expression<T>*) const;
        protected:
        private:
    };

    template <class T>
    T AndMin<T>::Evaluate(Expression<T>* left, Expression<T>* right) const
    {
        T l = left->Evaluate();
        T r = right->Evaluate();
        return (l>r)? r : l;
    }



}

#endif // ANDMIN_H
