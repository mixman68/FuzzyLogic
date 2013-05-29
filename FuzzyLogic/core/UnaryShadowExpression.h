//
//  BinaryShadowExpression.h
//  FuzzyLogic
//
//  Created by Clément Raussin on 08/04/13.
//  Copyright (c) 2013 Clément Raussin. All rights reserved.
//

#ifndef __FuzzyLogic__UnaryShadowExpression__
#define __FuzzyLogic__UnaryShadowExpression__

#include <iostream>
#include "NullExpressionException.h"
#include "UnaryExpression.h"

namespace core
{
    template <class T>
    class UnaryShadowExpression : public UnaryExpression<T>
    {
    public:
        UnaryShadowExpression();
        UnaryShadowExpression(UnaryExpression<T>*);
        virtual T Evaluate(Expression<T>*) const;
        virtual void SetTarget(UnaryExpression<T>*);
    protected:
    private:
        UnaryExpression<T>* target;
    };

    template<class T>
    UnaryShadowExpression<T>::UnaryShadowExpression()
    {
    }

    template<class T>
    UnaryShadowExpression<T>::UnaryShadowExpression(UnaryExpression<T>* _target):target(_target)
    {

    }

    template<class T>
    void UnaryShadowExpression<T>::SetTarget(UnaryExpression<T>* _target)
    {
        target = _target;
    }

    template<class T>
    T UnaryShadowExpression<T>::Evaluate(Expression<T>* l) const
    {
        return target->Evaluate(l);
    }


}

#endif /* defined(__FuzzyLogic__UnaryShadowExpression__) */
