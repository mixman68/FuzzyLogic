#ifndef UNARYEXPRESSIONMODEL_H
#define UNARYEXPRESSIONMODEL_H
#include "UnaryExpression.h"

namespace core
{
    template <class T>
    class UnaryExpressionModel: public UnaryExpression<T>
    {
        public:
            virtual T Evaluate() const;
        protected:
        private:
    };

    template<class T>
    T UnaryExpressionModel<T>::Evaluate() const
    {
       /* if(operator !=NULL)
            return operator.evaluate(o);
        return NULL;*/
    }

}

#endif // UNARYEXPRESSIONMODEL_H
