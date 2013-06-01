#include "SugenoException.h"

SugenoException::SugenoException(const char* m):
errorDescription(m)
{}
std::ostream& SugenoException::PrintOn(std::ostream& os)
const
{
    return os << "Sugeno Defuzz Exception : "<< errorDescription;
}
