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
             Expression<T>* NewAnd(Expression<T>*,Expression<T>*);
             Expression<T>* NewOr(Expression<T>*,Expression<T>*);
             Expression<T>* NewThen(Expression<T>*,Expression<T>*);
             Expression<T>* NewAgg(Expression<T>*,Expression<T>*);
             Expression<T>* NewDefyzz(Expression<T>*,Expression<T>*);
             Expression<T>* NewNot(Expression<T>*);
             Expression<T>* NewIs(fuzzy::is<T>*, Expression<T>*);
        protected:
        private:
    };
}

#endif // FUZZYFACTORY_H
