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
    T AggPlus<T>::Evaluate(Expression<T>* left, Expression<T>* right) const
    {
        T l = left->Evaluate();
        T r = right->Evaluate();
        T res = l+r;
        return (res<1)? res : 1;

    }
}

#endif // AGGPLUS_H
