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
            UnaryExpressionModel();
            UnaryExpressionModel(UnaryExpression<T>*,Expression<T>*);
            virtual T Evaluate() const;
            virtual T Evaluate(Expression<T>*) const;
            virtual void SetOperareur(UnaryExpression<T>*);
            virtual void SetOperand(Expression<T>*);
        protected:
        private:
            UnaryExpression<T>* operateur;
            Expression<T>* operand;
    };

    template<class T>
    UnaryExpressionModel<T>::UnaryExpressionModel()
    {
    }

    template<class T>
    UnaryExpressionModel<T>::UnaryExpressionModel(UnaryExpression<T>* _operateur,Expression<T>* _operand)
    {
        operand=_operand;
        operateur=_operateur;
    }

    template<class T>
    T UnaryExpressionModel<T>::Evaluate(Expression<T>* o) const
    {
        if(operateur == NULL)
            throw (NullExpressionException("operator missing"));
        return operateur->Evaluate(o);
    }

    template<class T>
    T UnaryExpressionModel<T>::Evaluate() const
    {
        if(operand !=NULL)
            throw (NullExpressionException("operand missing"));
        return Evaluate(&operand);
    }

    template<class T>
    void UnaryExpressionModel<T>::SetOperareur(UnaryExpression<T>* _operateur)
    {
        operateur=_operateur;
    }

    template<class T>
    void UnaryExpressionModel<T>::SetOperand(Expression<T>* _operand)
    {
        operand=_operand;
    }

}

#endif // UNARYEXPRESSIONMODEL_H
