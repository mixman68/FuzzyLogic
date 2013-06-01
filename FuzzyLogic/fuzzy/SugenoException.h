#ifndef SUGENOEXCEPTION_H
#define SUGENOEXCEPTION_H


class SugenoException
{
public:
    SugenoException(const char*);
    virtual std::ostream& PrintOn(std::ostream&) const;
private:
    const char* errorDescription;
};

#endif // SUGENOEXCEPTION_H
