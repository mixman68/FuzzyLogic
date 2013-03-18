//
//  NullExpressionException.h
//  FuzzyLogic
//
//  Created by Clément Raussin on 13/03/13.
//  Copyright (c) 2013 Clément Raussin. All rights reserved.
//

#ifndef __FuzzyLogic__NullExpressionException__
#define __FuzzyLogic__NullExpressionException__

#include <iostream>

class NullExpressionException
{
public:
    NullExpressionException(const char*);
    virtual std::ostream& PrintOn(std::ostream&)
    const;
private:
};

#endif /* defined(__FuzzyLogic__NullExpressionException__) */
