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
#include "UnaryExpression.h"

namespace core
{
    template <class T>
    class UnaryShadowExpression : public UnaryExpression<T>
    {
    public:
        UnaryShadowExpression();
        UnaryShadowExpression(UnaryExpression<T>*,Expression<T>*,Expression<T>*);
        /*virtual T Evaluate() const;
         virtual T Evaluate(Expression<T>*,Expression<T>*) const;
         virtual void SetOperareur(BinaryExpression<T>*);
         virtual void SetLeft(Expression<T>*);
         virtual void SetRight(Expression<T>*);*/
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
    
    /*template<class T>
     BinaryShadowExpression<T>::BinaryShadowExpression(BinaryExpression<T>* _operateur,Expression<T>* _left,Expression<T>* _right)
     {
     left=_left;
     right=_right;
     operateur=_operateur;
     }*/
    
}

#endif /* defined(__FuzzyLogic__BinaryShadowExpression__) */
