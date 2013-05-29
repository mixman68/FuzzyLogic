#ifndef ORMAX_H
#define ORMAX_H

#include "Or.h"

namespace fuzzy
{
    template <class T>
    class OrMax: public Or<T>
    {
        public:
            virtual T Evaluate(Expression<T>*,Expression<T>*) const;
        protected:
        private:
    };

    template <class T>
    T OrMax<T>::Evaluate(Expression<T>* left, Expression<T>* right) const
    {
        T l = left->Evaluate();
        T r = right->Evaluate();
        return (l>r)? l : r;
    }
    
    
    
}

#endif // ORMAX_H
