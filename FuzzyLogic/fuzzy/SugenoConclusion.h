#ifndef SUGENOCONCLUSION_H
#define SUGENOCONCLUSION_H

#include "../core/NaryExpression.h"
#include "SugenoException.h"

using namespace std;

namespace fuzzy
{
template<class T>
class SugenoConclusion: public core::NaryExpression<T>
{
public:
    SugenoConclusion();
    SugenoConclusion(const vector<T>*);
    virtual ~SugenoConclusion() {};

    virtual T Evaluate(std::vector<core::Expression<T>*>*) const;

protected:
private:
    const vector<T> *coefs;
};

template<class T>
SugenoConclusion<T>::SugenoConclusion(const vector<T>* _coefs):
    coefs(_coefs)
{
}

template<class T>
T SugenoConclusion <T>::Evaluate(vector<core::Expression<T>*> *operands) const
{

    //Creation des it�raturs
    typename vector<T>::const_iterator cItr;
    typename vector<core::Expression<T>*>::const_iterator oItr;

    T tmp = 0;

    for(cItr=coefs->begin(),oItr=operands->begin(); cItr != coefs->end()&&oItr != operands->end(); cItr++, oItr++)
    {
        T tmp2 = (*oItr)->Evaluate();
        tmp += (*cItr) * tmp2;
    }

    if(oItr != operands->end())
        throw(new SugenoException("erreur"));

    return tmp;
}
}


#endif // SUGENOCONCLUSION_H
