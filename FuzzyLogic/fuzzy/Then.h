#ifndef THEN_H
#define THEN_H

#include "../core/BinaryExpression.h"
#include "../core/Expression.h"

using namespace core;

namespace fuzzy
{
    template <class T>
    class Then: public BinaryExpression<T>
    {
        public:
            virtual T Evaluate(Expression<T>*,Expression<T>*) const;
        protected:
        private:
    };
}

#endif // THEN_H
