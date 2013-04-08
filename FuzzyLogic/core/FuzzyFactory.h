#ifndef FUZZYFACTORY_H
#define FUZZYFACTORY_H

#include "ExpressionFactory.h"
#include "ValueModel.h"
#include "../fuzzy/Is.h"

namespace core
{
    template <class T>
    class FuzzyFactory: public ExpressionFactory<T>
    {
        public:
             Expression<T>* newAnd(Expression<T>*,Expression<T>*);
             Expression<T>* newOr(Expression<T>*,Expression<T>*);
             Expression<T>* newThen(Expression<T>*,Expression<T>*);
             Expression<T>* newAgg(Expression<T>*,Expression<T>*);
             Expression<T>* newDefyzz(Expression<T>*,Expression<T>*);
             Expression<T>* newNot(Expression<T>*);
             Expression<T>* newIs(fuzzy::is<T>*, Expression<T>*);
        protected:
        private:
    };
}

#endif // FUZZYFACTORY_H
