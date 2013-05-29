#ifndef EXPRESSIONFACTORY_H
#define EXPRESSIONFACTORY_H

#include "Expression.h"
#include "UnaryExpressionModel.h"
#include "BinaryExpressionModel.h"

#include <vector>

namespace core
{
    template <class T>
    class ExpressionFactory
    {
        public:
            Expression<T>* Hold(Expression<T>* );
            UnaryExpressionModel<T>* NewUnary(UnaryExpression<T>*,Expression<T>*);
            BinaryExpressionModel<T>*  NewBinary(BinaryExpression<T>*,Expression<T>*,Expression<T>*);
        protected:
        private:
            std::vector<Expression<T>*> memory;
    };


    template<class T>
    Expression<T>* ExpressionFactory<T>::Hold(Expression<T>* expr)
    {
        memory.push_back(expr);
        return expr;
    }

    template<class T>
    UnaryExpressionModel<T>* ExpressionFactory<T>::NewUnary(UnaryExpression<T>* ope, Expression<T>* o)
    {
        UnaryExpressionModel<T>* tmp = new UnaryExpressionModel<T>(ope,o);
        memory.push_back(tmp);
        return tmp;
    }

    template<class T>
    BinaryExpressionModel<T>* ExpressionFactory<T>::NewBinary(BinaryExpression<T>* ope, Expression<T>* l, Expression<T>* r)
    {
        BinaryExpressionModel<T>* tmp = new BinaryExpressionModel<T>(ope,l,r);
        memory.push_back(tmp);
        return tmp;
    }

}

#endif // EXPRESSIONFACTORY_H
