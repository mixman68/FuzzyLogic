#ifndef COGDEFUZZ_H
#define COGDEFUZZ_H

#include "MamdaniDefuzz.h"

using namespace core;

namespace fuzzy
{
template <class T>
class CogDefuzz: public MamdaniDefuzz<T>
{
public:
    CogDefuzz(const T&,const T&,const T&);
    virtual T Evaluate(Expression<T>*,Expression<T>*) const;
protected:
private:
};

template <class T>
T CogDefuzz<T>::Evaluate(Expression<T>* left,Expression<T>* right) const
{
    Shape<T> s((ValueModel<T>*)left, right, this->mini, this->maxi, this->step);

    T num,dem ,res;
    num=0;
    dem=0;

    for(T i = this->mini; i< this->maxi; i+=this->step)
    {
        num += s.getShape().second.at(i) * s.getShape().first.at(i);
        dem += s.getShape().second.at(i);
    }

    //resultat
    res = num / dem;

    return res;
}

template <class T>
CogDefuzz<T>::CogDefuzz(const T& _min, const T& _max, const T& _step):
	MamdaniDefuzz<T>(_min,_max,_step)
	{
	}

}

#endif // COGDEFUZZ_H
