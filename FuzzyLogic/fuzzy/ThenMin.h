#ifndef THENMIN_H
#define THENMIN_H

#include "Then.h"

namespace fuzzy
{
    template <class T>
    class ThenMin: public Then<T>
    {
        public:
            virtual T Evaluate(Expression<T>*,Expression<T>*) const;
        protected:
        private:
    };

    template <class T>
    T ThenMin<T>::Evaluate(Expression<T>* left, Expression<T>* right) const
    {
        T l = left->Evaluate();
        T r = right->Evaluate();
        return (l>r)? r : l;

    }
}
#endif // THENMIN_H
