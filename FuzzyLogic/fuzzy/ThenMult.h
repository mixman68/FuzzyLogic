#ifndef THENMULT_H
#define THENMULT_H
#include "Then.h"

namespace fuzzy
{
    template <class T>
    class ThenMult: public Then<T>
    {
        public:
            virtual T Evaluate(Expression<T>*,Expression<T>*) const;
        protected:
        private:
    };

    template <class T>
    T ThenMult<T>::Evaluate(Expression<T>* left, Expression<T>* right) const
    {
        T l = left->Evaluate();
        T r = right->Evaluate();
        T res = l*r;
        return res;

    }
}
#endif // THENMULT_H
