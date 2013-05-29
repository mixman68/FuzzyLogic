//
//  NaryExpression.h
//  FuzzyLogic
//
//  Created by Clément Raussin on 15/05/13.
//  Copyright (c) 2013 Clément Raussin. All rights reserved.
//

#ifndef __FuzzyLogic__NaryExpression__
#define __FuzzyLogic__NaryExpression__

#include <iostream>
#include "Expression.h"
#include <vector>

namespace core{
    template <class T>
    class NaryExpression
    {
    public:
        virtual T Evaluate(std::vector<Expression<T>*>*) const = 0;
    protected:
    private:
    };
}

#endif /* defined(__FuzzyLogic__NaryExpression__) */
