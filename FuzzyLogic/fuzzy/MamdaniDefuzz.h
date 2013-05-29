#ifndef MAMDANIDEFUZZ_H
#define MAMDANIDEFUZZ_H

#include "../core/BinaryExpression.h"
#include "../core/Expression.h"
#include "../core/Shape.h"

using namespace core;

namespace fuzzy
{
    template <class T>
    class MamdaniDefuzz: public BinaryExpression<T>
    {
        public:
            MamdaniDefuzz();
            MamdaniDefuzz(const T&,const T&,const T&);
            virtual T Evaluate(Expression<T>*,Expression<T>*) const = 0;
        protected:
            T mini, maxi, step;
        private:
    };

    template<class T>
	MamdaniDefuzz<T>::MamdaniDefuzz():
	mini(0),maxi(0),step(0)
	{
	}

	template<class T>
	MamdaniDefuzz<T>::MamdaniDefuzz(const T& _min, const T& _max, const T& _step):
	mini(_min),maxi(_max),step(_step)
	{
	}

}

#endif // MAMDANIDEFUZZ_H
