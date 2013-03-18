#ifndef COGDEFUZZ_H
#define COGDEFUZZ_H

#include "MamdaniDefuzz.h"

using namespace core;

namespace fuzzy
{
    template <class T>
    class CogDefuzz: public MamdaniDefuzz<T>
    {
        public:
            virtual T Evaluate(Expression<T>*,Expression<T>*) const;
        protected:
        private:
    };
    template <class T>
    T CogDefuzz<T>::Evaluate(Expression<T>* left,Expression<T>* right) const
    {
        T l = left->Evaluate();
        T r = right->Evaluate();

    }

}

#endif // COGDEFUZZ_H
