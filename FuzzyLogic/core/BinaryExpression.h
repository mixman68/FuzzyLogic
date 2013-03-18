#ifndef BINARYEXPRESSION_H
#define BINARYEXPRESSION_H
#include "../common.h"
#include "Expression.h"

namespace core
{
    template <class T>
    class BinaryExpression
    {
        public:
            virtual T Evaluate(Expression<T>*, Expression<T>*) const = 0;
            virtual T Evaluate() const = 0;
        protected:
        private:
    };
}

#endif // BINARYEXPRESSION_H
