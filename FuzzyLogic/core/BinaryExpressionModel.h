#ifndef BINARYEXPRESSIONMODEL_H
#define BINARYEXPRESSIONMODEL_H
#include "BinaryExpression.h"

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
            BinaryExpression<T> operateur;
            Expression<T> left,right;
    };

    template<class T>
    T BinaryExpressionModel<T>::Evaluate(Expression<T>* l, Expression<T>* r) const
    {
        if(operateur !=NULL)
            return operateur.evaluate(l,r);
        return NULL;
    }

    template<class T>
    T BinaryExpressionModel<T>::Evaluate() const
    {
        if(left !=NULL && right !=NULL)
            return evaluate(&left,&right);
        return NULL;
    }

}

#endif // BINARYEXPRESSIONMODEL_H
