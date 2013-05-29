#ifndef FUZZYFACTORY_H
#define FUZZYFACTORY_H

#include "ExpressionFactory.h"
#include "ValueModel.h"
#include "../operator.h"
#include "../expr.h"
#include "../fuzzy/And.h"



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
             Expression<T>* NewMamdani(Expression<T>*,Expression<T>*);
             Expression<T>* NewNot(Expression<T>*);
             Expression<T>* NewIs(fuzzy::is<T>*, Expression<T>*);

             void changeAnd(fuzzy::And<T>*);
             void changeOr(fuzzy::Or<T>*);
             void changeThen(fuzzy::Then<T>*);
             void changeAgg(fuzzy::Agg<T>*);
             void changeMamdani(fuzzy::MamdaniDefuzz<T>*);
             void changeNot(fuzzy::Not<T>*);
        protected:
        private:
            BinaryShadowExpression<T>* et,ou,then,agg,defuzz,mamdani;
            UnaryShadowExpression<T>* non;

    };


    template <class T>
    Expression<T>* FuzzyFactory<T>::NewAnd(Expression<T>* l,Expression<T>* r)
    {
        return this->NewBinary(et,l,r);
    }

    template <class T>
    Expression<T>* FuzzyFactory<T>::NewOr(Expression<T>* l,Expression<T>* r)
    {
        return this->NewBinary(ou,l,r);
    }

    template <class T>
    Expression<T>* FuzzyFactory<T>::NewThen(Expression<T>* l,Expression<T>* r)
    {
        return this->NewBinary(then,l,r);
    }

    template <class T>
    Expression<T>* FuzzyFactory<T>::NewAgg(Expression<T>* l,Expression<T>* r)
    {
        return this->NewBinary(agg,l,r);
    }

    template <class T>
    Expression<T>* FuzzyFactory<T>::NewDefuzz(Expression<T>* l,Expression<T>* r)
    {
        return this->NewBinary(defuzz,l,r);
    }

    template <class T>
    Expression<T>* FuzzyFactory<T>::NewMamdani(Expression<T>* l,Expression<T>* r)
    {
        return this->NewBinary(mamdani,l,r);
    }

    template <class T>
    Expression<T>* FuzzyFactory<T>::NewNot(Expression<T>* expr)
    {
        return this->NewUnary(non,expr);
    }

    template <class T>
    Expression<T>* FuzzyFactory<T>::NewIs(fuzzy::is<T>* is, Expression<T>* e)
    {
        return this->NewUnary(is,e);
    }

    //CHANGE PART

    template <class T>
    void FuzzyFactory<T>::changeAnd(fuzzy::And<T>* o)
    {
        et->setTarget(o);
    }

    template <class T>
    void FuzzyFactory<T>::changeOr(fuzzy::Or<T>* o)
    {
        ou->setTarget(o);
    }

    template <class T>
    void FuzzyFactory<T>::changeThen(fuzzy::Then<T>* o)
    {
        then->setTarget(o);
    }

    template <class T>
    void FuzzyFactory<T>::changeAgg(fuzzy::Agg<T>* o)
    {
        agg->setTarget(o);
    }

    template <class T>
    void FuzzyFactory<T>::changeMamdani(fuzzy::MamdaniDefuzz<T>* o)
    {
        mamdani->setTarget(o);
    }

    template <class T>
    void FuzzyFactory<T>::changeNot(fuzzy::Not<T>* o)
    {
        non->setTarget(o);
    }

}

#endif // FUZZYFACTORY_H
