//
//  BinaryShadowExpression.h
//  FuzzyLogic
//
//  Created by Clément Raussin on 08/04/13.
//  Copyright (c) 2013 Clément Raussin. All rights reserved.
//

#ifndef __FuzzyLogic__BinaryShadowExpression__
#define __FuzzyLogic__BinaryShadowExpression__

#include <iostream>
#include "NullExpressionException.h"
#include "BinaryExpression.h"

namespace core
{
    template <class T>
    class BinaryShadowExpression : public BinaryExpression<T>
    {
    public:
        BinaryShadowExpression(BinaryExpression<T>*);
        virtual T Evaluate(Expression<T>*,Expression<T>*) const;
        virtual void SetTarget(BinaryExpression<T>*);
    protected:
    private:
        BinaryExpression<T>* target;
    };
    
    template<class T>
    BinaryShadowExpression<T>::BinaryShadowExpression(BinaryExpression<T>* _target): target(_target)
    {
    }
    
    template<class T>
    void BinaryShadowExpression<T>::SetTarget(BinaryExpression<T>* _target)
    {
        target = _target;
    }
    
    template<class T>
    T BinaryShadowExpression<T>::Evaluate(Expression<T>* l,Expression<T>* r) const
    {
        return target->Evaluate(l, r);
    }
}

#endif /* defined(__FuzzyLogic__BinaryShadowExpression__) */
