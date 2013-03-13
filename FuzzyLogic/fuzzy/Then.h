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
<<<<<<< HEAD
=======

>>>>>>> d2b5b4cc0d012bec25f9c9986ea358680e848102
#endif // THEN_H
