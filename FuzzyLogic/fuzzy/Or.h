#ifndef OR_H
#define OR_H


#include "../core/BinaryExpression.h"
#include "../core/Expression.h"

using namespace core;

namespace fuzzy
{
    template <class T>
    class Or: public BinaryExpression<T>
    {
        public:
            virtual T Evaluate(Expression<T>*,Expression<T>*) const = 0;
        protected:
        private:
    };
}

#endif // OR_H
