#ifndef EXPRESSIONFACTORY_H
#define EXPRESSIONFACTORY_H

#include "Expression.h"

namespace core
{
    template <class T>
    class ExpressionFactory
    {
        public:
            Expression Hold(Expression);
            newUnary(UnaryExpression,Expression);
            newBinary(BinaryExpression,Expression,Expression);
        protected:
        private:
    };


    template<class T>
    ExpressionFactory<T>::Hold(Expression expr)
    {
        //todo
        return NULL;
    }

    template<class T>
    ExpressionFactory<T>::newUnary(UnaryExpression ope, Expression o)
    {
        return new UnaryExpressionModel(ope,o);
    }

    template<class T>
    ExpressionFactory<T>::newBinary(BinaryExpression ope, Expression l, Expression r)
    {
        return new BinaryExpressionModel(ope,l,r);
    }

}

#endif // EXPRESSIONFACTORY_H
