#ifndef UNARYEXPRESSIONMODEL_H
#define UNARYEXPRESSIONMODEL_H
#include "UnaryExpression.h"
#include "NullExpressionException.h"

namespace core
{
    template <class T>
    class UnaryExpressionModel: public UnaryExpression<T>,Expression<T>
    {
        public:
            virtual T Evaluate() const;
            virtual T Evaluate(Expression<T>*) const;
        protected:
        private:
            UnaryExpression<T>* operateur;
            Expression<T>* operand;
    };


    template<class T>
    T UnaryExpressionModel<T>::Evaluate(Expression<T>* o) const
    {
        if(operateur == NULL)
            throw (NullExpressionException("operator missing"));
        return operateur->evaluate(o);
    }

    template<class T>
    T UnaryExpressionModel<T>::Evaluate() const
    {
        if(operand !=NULL)
            throw (NullExpressionException("operator missing"));
        return Evaluate(&operand);
    }

}

#endif // UNARYEXPRESSIONMODEL_H
