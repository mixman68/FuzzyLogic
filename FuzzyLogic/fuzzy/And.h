#ifndef AND_H
#define AND_H

#include "../core/BinaryExpression.h"
#include "../core/Expression.h"

using namespace core;

namespace fuzzy
{
    template <class T>
    class And: public BinaryExpression<T>
    {
        public:
            virtual T Evaluate(Expression<T>*,Expression<T>*) const;
        protected:
        private:
    };
}

#endif // AND_H
