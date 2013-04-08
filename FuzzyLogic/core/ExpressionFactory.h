#ifndef EXPRESSIONFACTORY_H
#define EXPRESSIONFACTORY_H

#include "Expression.h"
#include "UnaryExpressionModel.h"
#include "BinaryExpressionModel.h"

namespace core
{
    template <class T>
    class ExpressionFactory
    {
        public:
            Expression<T> Hold(Expression<T>);
            UnaryExpressionModel<T> newUnary(UnaryExpression<T>,Expression<T>);
            BinaryExpressionModel<T>  newBinary(BinaryExpression<T>,Expression<T>,Expression<T>);
        protected:
        private:
    };


    template<class T>
    Expression<T> ExpressionFactory<T>::Hold(Expression<T> expr)
    {
        //todo
        return NULL;
    }

    template<class T>
    UnaryExpressionModel<T> ExpressionFactory<T>::newUnary(UnaryExpression<T> ope, Expression<T> o)
    {
        return new UnaryExpressionModel<T>(ope,o);
    }

    template<class T>
    BinaryExpressionModel<T> ExpressionFactory<T>::newBinary(BinaryExpression<T> ope, Expression<T> l, Expression<T> r)
    {
        return new BinaryExpressionModel<T>(ope,l,r);
    }

}

#endif // EXPRESSIONFACTORY_H
