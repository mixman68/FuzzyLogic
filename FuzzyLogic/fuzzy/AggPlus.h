#ifndef AGGPLUS_H
#define AGGPLUS_H


#include "Agg.h"

namespace fuzzy
{
    template <class T>
    class AggPlus: public Agg<T>
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

    }
}

#endif // AGGPLUS_H
