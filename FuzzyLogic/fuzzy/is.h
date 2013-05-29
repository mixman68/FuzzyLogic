#ifndef IS_H
#define IS_H


#include "../core/UnaryExpression.h"
#include "../core/Expression.h"

using namespace core;

namespace fuzzy
{
    template <class T>
    class is: public UnaryExpression<T>
    {
        public:
            virtual T Evaluate(Expression<T>*) const = 0;
        protected:
        private:
    };
}

#endif // IS_H
