#ifndef UNARYEXPRESSIONMODEL_H
#define UNARYEXPRESSIONMODEL_H
#include "UnaryExpression.h"

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
            UnaryExpression<T> operateur;
            Expression<T> operand;
    };


    template<class T>
    T UnaryExpressionModel<T>::Evaluate(Expression<T>* o) const
    {
        if(operateur !=NULL)
            return operateur.evaluate(o);
        return NULL;
    }

    template<class T>
    T UnaryExpressionModel<T>::Evaluate() const
    {
        if(operand !=NULL)
            return evaluate(operand);
        return NULL;
    }

}

#endif // UNARYEXPRESSIONMODEL_H
