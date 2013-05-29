//
//  NullExpressionException.cpp
//  FuzzyLogic
//
//  Created by Clément Raussin on 13/03/13.
//  Copyright (c) 2013 Clément Raussin. All rights reserved.
//

#include "NullExpressionException.h"

NullExpressionException::NullExpressionException(const char* m):
errorDescription(m)
{}
std::ostream& NullExpressionException::PrintOn(std::ostream& os)
const
{
    return os << "Null Expression Exception : "<< errorDescription;
}
