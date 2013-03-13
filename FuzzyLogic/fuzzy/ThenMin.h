#ifndef THENMIN_H
#define THENMIN_H

#include "Then.h"

<<<<<<< HEAD
=======

>>>>>>> d2b5b4cc0d012bec25f9c9986ea358680e848102
namespace fuzzy
{
    template <class T>
    class ThenMin: public Then<T>
    {
        public:
            virtual T Evaluate(Expression<T>*,Expression<T>*) const;
        protected:
        private:
    };

    template <class T>
    T ThenMin<T>::Evaluate(Expression<T>* left, Expression<T>* right) const
    {
        T l = left->Evaluate();
        T r = right->Evaluate();

    }
}
<<<<<<< HEAD

=======
>>>>>>> d2b5b4cc0d012bec25f9c9986ea358680e848102
#endif // THENMIN_H
