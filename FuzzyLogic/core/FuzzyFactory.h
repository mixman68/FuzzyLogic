#ifndef FUZZYFACTORY_H
#define FUZZYFACTORY_H

#include "ExpressionFactory.h"
#include "ValueModel.h"
#include "../operator.h"
#include "../expr.h"
#include "BinaryShadowExpression.h"
#include "UnaryShadowExpression.h"


namespace core
{
    template <class T>
    class FuzzyFactory: public ExpressionFactory<T>
    {
        public:
             Expression<T>* NewAnd(Expression<T>*,Expression<T>*);
             Expression<T>* NewOr(Expression<T>*,Expression<T>*);
             Expression<T>* NewThen(Expression<T>*,Expression<T>*);
             Expression<T>* NewAgg(Expression<T>*,Expression<T>*);
             Expression<T>* NewDefuzz(Expression<T>*,Expression<T>*);
             Expression<T>* NewNot(Expression<T>*);
             Expression<T>* NewIs(fuzzy::is<T>*, Expression<T>*);
        protected:
        private:
            BinaryShadowExpression<T>* cul;
            UnaryShadowExpression<T>* non;
    };


    template <class T>
    Expression<T>* FuzzyFactory<T>::NewAnd(Expression<T>* l,Expression<T>* r)
    {

    }

    template <class T>
    Expression<T>* FuzzyFactory<T>::NewOr(Expression<T>* l,Expression<T>* r)
    {

    }

    template <class T>
    Expression<T>* FuzzyFactory<T>::NewThen(Expression<T>* l,Expression<T>* r)
    {

    }

    template <class T>
    Expression<T>* FuzzyFactory<T>::NewAgg(Expression<T>* l,Expression<T>* r)
    {

    }

    template <class T>
    Expression<T>* FuzzyFactory<T>::NewDefuzz(Expression<T>* l,Expression<T>* r)
    {

    }

    template <class T>
    Expression<T>* FuzzyFactory<T>::NewNot(Expression<T>* expr)
    {

    }

    template <class T>
    Expression<T>* FuzzyFactory<T>::NewIs(fuzzy::is<T>* is, Expression<T>* e)
    {

    }
}

#endif // FUZZYFACTORY_H
