#ifndef BINARYEXPRESSIONMODEL_H
#define BINARYEXPRESSIONMODEL_H
#include "BinaryExpression.h"
#include "NullExpressionException.h"

namespace core
{
    template <class T>
    class BinaryExpressionModel: public BinaryExpression<T>, Expression<T>
    {
        public:
            virtual T Evaluate() const;
            virtual T Evaluate(Expression<T>*,Expression<T>*) const;
        protected:
        private:
            BinaryExpression<T>* operateur;
            Expression<T>* left,right;
    };

    template<class T>
    T BinaryExpressionModel<T>::Evaluate(Expression<T>* l, Expression<T>* r) const
    {
        if(operateur == NULL)
            throw (NullExpressionException("operator missing"));
        return operateur->Evaluate();
    }

    template<class T>
    T BinaryExpressionModel<T>::Evaluate() const
    {
        if(left == NULL)
            throw (NullExpressionException("left operand missing"));
        if(right == NULL)
            throw (NullExpressionException("right operand missing"));

        return Evaluate(&left,&right);
    }

}

#endif // BINARYEXPRESSIONMODEL_H
