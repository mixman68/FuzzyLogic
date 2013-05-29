#ifndef NOT_H
#define NOT_H


#include "../core/UnaryExpression.h"
#include "../core/Expression.h"

using namespace core;

namespace fuzzy
{
    template <class T>
    class Not: public UnaryExpression<T>
    {
        public:
            virtual T Evaluate(Expression<T>*) const = 0;
        protected:
        private:
    };
}

#endif // NOT_H
