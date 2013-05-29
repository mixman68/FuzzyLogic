#ifndef AGGMAX_H
#define AGGMAX_H

#include "Agg.h"

namespace fuzzy
{
    template <class T>
    class AggMax: public Agg<T>
    {
        public:
            virtual T Evaluate(Expression<T>*,Expression<T>*) const;
        protected:
        private:
    };

    template <class T>
    T AggMax<T>::Evaluate(Expression<T>* left, Expression<T>* right) const
    {
        T l = left->Evaluate();
        T r = right->Evaluate();
        return (l>r)? l : r;

    }
}

#endif // AGGMAX_H
