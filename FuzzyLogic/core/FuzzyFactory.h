#ifndef FUZZYFACTORY_H
#define FUZZYFACTORY_H

#include "ExpressionFactory.h"
#include "ValueModel.h"
#include "../operator.h"
#include "../expr.h"
#include "../fuzzy/And.h"
#include "../fuzzy/MamdaniDefuzz.h"



namespace fuzzy
{
template <class T>
class FuzzyFactory: public ExpressionFactory<T>
{
public:
    FuzzyFactory(fuzzy::Not<T>*,fuzzy::And<T>*,fuzzy::Or<T>*,fuzzy::Agg<T>*,fuzzy::Then<T>*,fuzzy::MamdaniDefuzz<T>*,fuzzy::SugenoDefuzz<T>*,fuzzy::SugenoConclusion<T>*);
    Expression<T>* NewAnd(Expression<T>*,Expression<T>*);
    Expression<T>* NewOr(Expression<T>*,Expression<T>*);
    Expression<T>* NewThen(Expression<T>*,Expression<T>*);
    Expression<T>* NewAgg(Expression<T>*,Expression<T>*);
    Expression<T>* NewDefuzz(Expression<T>*,Expression<T>*);
    Expression<T>* NewMamdani(Expression<T>*,Expression<T>*);
    Expression<T>* NewNot(Expression<T>*);
    Expression<T>* NewIs(fuzzy::is<T>*, Expression<T>*);

    void ChangeAnd(fuzzy::And<T>*);
    void ChangeOr(fuzzy::Or<T>*);
    void ChangeThen(fuzzy::Then<T>*);
    void ChangeAgg(fuzzy::Agg<T>*);
    void ChangeMamdani(fuzzy::MamdaniDefuzz<T>*);
    void ChangeNot(fuzzy::Not<T>*);
    void ChangeSugeno(fuzzy::SugenoDefuzz<T>* o);
	void ChangeConclusion(fuzzy::SugenoConclusion<T>* o);
protected:
private:
    BinaryShadowExpression<T> et,ou,then,agg,defuzz,mamdani;
    UnaryShadowExpression<T>* non;
    NaryShadowExpression<T> sugeno,conclusion;

};

template <class T>
FuzzyFactory<T>::FuzzyFactory(fuzzy::Not<T>* _non,
                              fuzzy::And<T>* _et,
                              fuzzy::Or<T>* _ou,
                              fuzzy::Agg<T>* _agg,
                              fuzzy::Then<T>* _then,
                              fuzzy::MamdaniDefuzz<T>* _mamdani,
                              fuzzy::SugenoDefuzz<T>* _sugeno,
                              fuzzy::SugenoConclusion<T>* _conclusion):
    non(new core::UnaryShadowExpression<T>(_non)),
    ou(new core::BinaryShadowExpression<T>(_et)),
    et(new core::BinaryShadowExpression<T>(_ou)),
    agg(new core::BinaryShadowExpression<T>(_agg)),
    then(new core::BinaryShadowExpression<T>(_then)),
    mamdani(new core::BinaryShadowExpression<T>(_mamdani)),
    sugeno(new core::NaryShadowExpression<T>(_sugeno)),
    conclusion(new core::NaryShadowExpression<T>(_conclusion))
{
}


template <class T>
Expression<T>* FuzzyFactory<T>::NewAnd(Expression<T>* l,Expression<T>* r)
{
    return this->NewBinary(&et,l,r);
}

template <class T>
Expression<T>* FuzzyFactory<T>::NewOr(Expression<T>* l,Expression<T>* r)
{
    return this->NewBinary(&ou,l,r);
}

template <class T>
Expression<T>* FuzzyFactory<T>::NewThen(Expression<T>* l,Expression<T>* r)
{
    return this->NewBinary(&then,l,r);
}

template <class T>
Expression<T>* FuzzyFactory<T>::NewAgg(Expression<T>* l,Expression<T>* r)
{
    return this->NewBinary(&agg,l,r);
}

template <class T>
Expression<T>* FuzzyFactory<T>::NewDefuzz(Expression<T>* l,Expression<T>* r)
{
    return this->NewBinary(&defuzz,l,r);
}

template <class T>
Expression<T>* FuzzyFactory<T>::NewMamdani(Expression<T>* l,Expression<T>* r)
{
    return this->NewBinary(&mamdani,l,r);
}

template <class T>
Expression<T>* FuzzyFactory<T>::NewNot(Expression<T>* expr)
{
    return this->NewUnary(&non,expr);
}

template <class T>
Expression<T>* FuzzyFactory<T>::NewIs(fuzzy::is<T>* is, Expression<T>* e)
{
    return this->NewUnary(is,e);
}

//Change PART

template <class T>
void FuzzyFactory<T>::ChangeAnd(fuzzy::And<T>* o)
{
    et.SetTarget(o);
}

template <class T>
void FuzzyFactory<T>::ChangeOr(fuzzy::Or<T>* o)
{
    ou.SetTarget(o);
}

template <class T>
void FuzzyFactory<T>::ChangeThen(fuzzy::Then<T>* o)
{
    then.SetTarget(o);
}

template <class T>
void FuzzyFactory<T>::ChangeAgg(fuzzy::Agg<T>* o)
{
    agg.SetTarget(o);
}

template <class T>
void FuzzyFactory<T>::ChangeMamdani(fuzzy::MamdaniDefuzz<T>* o)
{
    mamdani.SetTarget(o);
}

template <class T>
void FuzzyFactory<T>::ChangeNot(fuzzy::Not<T>* o)
{
    non.SetTarget(o);
}

	template<class T>
	void FuzzyFactory<T>::ChangeSugeno(SugenoDefuzz<T>* o)
	{
		sugeno.SetTarget(o);
	}

	template<class T>
	void FuzzyFactory<T>::ChangeConclusion(SugenoConclusion<T>* o)
	{
		conclusion.SetTarget(o);
	}

}

#endif // FUZZYFACTORY_H
