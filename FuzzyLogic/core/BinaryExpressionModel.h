#ifndef BINARYEXPRESSIONMODEL_H
#define BINARYEXPRESSIONMODEL_H
#include "BinaryExpression.h"

namespace core
{
    template <class T>
    class BinaryExpressionModel: public BinaryExpression<T>
    {
        public:
            virtual T Evaluate() const;
        protected:
        private:
            BinaryExpression<T> operateur;
    };

    template<class T>
    T BinaryExpressionModel<T>::Evaluate() const
    {
        /*if(operateur !=NULL)
            return operateur.evaluate(o);
        return NULL;*/
    }

}

#endif // BINARYEXPRESSIONMODEL_H
