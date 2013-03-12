#ifndef UNARYEXPRESSION_H
#define UNARYEXPRESSION_H
#include "../common.h"
#include "Expression.h"

namespace core
{
    template <class T>
    class UnaryExpression
    {
        public:
            virtual T Evaluate(Expression<T>) const = 0;
        protected:
        private:
    };
}

#endif // UNARYEXPRESSION_H
