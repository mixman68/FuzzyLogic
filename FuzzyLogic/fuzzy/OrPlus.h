#ifndef ORPLUS_H
#define ORPLUS_H

#include "Or.h"

namespace fuzzy
{
    template <class T>
    class OrPlus: public Or<T>
    {
        public:
            virtual T Evaluate(Expression<T>*,Expression<T>*) const;
        protected:
        private:
    };

    template <class T>
    T OrPlus<T>::Evaluate(Expression<T>* left, Expression<T>* right) const
    {
        T l = left->Evaluate();
        T r = right->Evaluate();
        T res = l+r;
        return (res<1)? res : 1;
    }
}
#endif // ORPLUS_H
