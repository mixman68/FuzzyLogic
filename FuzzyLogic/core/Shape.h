#ifndef SHAPE_H
#define SHAPE_H

#include <vector>
#include "../expr.h"

//La value model ne sert que pour pouvoir evaluer une expresssion

namespace core
{
    template<class T>
    class Shape
    {
        public:
            Shape(ValueModel<T>*, Expression<T>*,const T&, const T&, const T&);
            typedef std::pair <std::vector<T>, std::vector<T> > ShapeVect;
            ShapeVect getShape() const;
        protected:
        private:
            ShapeVect shape;
    };

    template<class T>
    Shape<T>::Shape(ValueModel<T>* value, Expression<T>* e,const T& mini, const T& maxi, const T& step)
    {
        // Constructrion de la shape
        std::vector<T> x,y; // deux vecteur temporaires qu'on va mettre dans la paire shape
		for (T i=mini; i <= maxi; i+= step)
		{
		    x.push_back(i); // on stocke le x
			value->setValue(i); // set de la valeur pour evaluer le y
			T tmp = e->evaluate(); // on evalue le y
			y.push_back(tmp); // et on le stocke
		}
        this->shape = ShapeVect(x,y);
    }

    template<class T>
    typename Shape<T>::ShapeVect Shape<T>::getShape() const
    {
        return shape;
    }
}


#endif // SHAPE_H
