#ifndef BINARYEXPRESSIONMODEL_H
#define BINARYEXPRESSIONMODEL_H
#include "BinaryExpression.h"
#include "NullExpressionException.h"

namespace core
{
    template <class T>
    class BinaryExpressionModel: public BinaryExpression<T>, public Expression<T>
    {
        public:
            BinaryExpressionModel();
            BinaryExpressionModel(BinaryExpression<T>*,Expression<T>*,Expression<T>*);
            virtual T Evaluate() const;
            virtual T Evaluate(Expression<T>*,Expression<T>*) const;
            virtual void SetOperareur(BinaryExpression<T>*);
            virtual void SetLeft(Expression<T>*);
            virtual void SetRight(Expression<T>*);
        protected:
        private:
            BinaryExpression<T>* operateur;
            Expression<T>* left;
            Expression<T>* right;
    };

    template<class T>
    BinaryExpressionModel<T>::BinaryExpressionModel()
    {
    }

    template<class T>
    BinaryExpressionModel<T>::BinaryExpressionModel(BinaryExpression<T>* _operateur,Expression<T>* _left,Expression<T>* _right):
    left(_left), right(_right), operateur(_operateur)
    {
    }

    template<class T>
    T BinaryExpressionModel<T>::Evaluate(Expression<T>* l, Expression<T>* r) const
    {
        if(operateur == NULL)
            throw (NullExpressionException("operator missing"));
        return operateur->Evaluate(l,r);
    }

    template<class T>
    T BinaryExpressionModel<T>::Evaluate() const
    {
        if(left == NULL)
            throw (NullExpressionException("left operand missing"));
        if(right == NULL)
            throw (NullExpressionException("right operand missing"));

        return Evaluate(left,right);
    }

    template<class T>
    void BinaryExpressionModel<T>::SetOperareur(BinaryExpression<T>* _operateur)
    {
        operateur=_operateur;
    }

    template<class T>
    void BinaryExpressionModel<T>::SetLeft(Expression<T>* _left)
    {
        left=_left;
    }

    template<class T>
    void BinaryExpressionModel<T>::SetRight(Expression<T>* _right)
    {
        right=_right;
    }

}

#endif // BINARYEXPRESSIONMODEL_H
