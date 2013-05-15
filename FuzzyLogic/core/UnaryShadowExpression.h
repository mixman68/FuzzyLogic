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
        UnaryShadowExpression(UnaryExpression<T>*,Expression<T>*,Expression<T>*);
    protected:
    private:
        /*BinaryExpression<T>* operateur;
         Expression<T>* left;
         Expression<T>* right;*/
    };
    
    template<class T>
    UnaryShadowExpression<T>::UnaryShadowExpression()
    {
    }
    
    
}

#endif /* defined(__FuzzyLogic__UnaryShadowExpression__) */
