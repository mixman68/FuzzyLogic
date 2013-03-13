#ifndef MAMDANIDEFUZZ_H
#define MAMDANIDEFUZZ_H

#include "../core/BinaryExpression.h"
#include "../core/Expression.h"

using namespace core;

namespace fuzzy
{
    template <class T>
    class MamdaniDefuzz: public BinaryExpression<T>
    {
        public:
            virtual T Evaluate(Expression<T>*,Expression<T>*) const;
        protected:
        private:
    };
    template <class T>
    T MamdaniDefuzz<T>::Evaluate(Expression<T>* left,Expression<T>* right) const
    {
        T l = left->Evaluate();
        T r = right->Evaluate();

    }

}

#endif // MAMDANIDEFUZZ_H
