#ifndef EXPRESSION_H
#define EXPRESSION_H
#include "../common.h"

namespace core
{
    template <class T>
    class Expression
    {
        public:
            virtual T Evaluate() const = 0;
        protected:
        private:
    };
}
#endif // EXPRESSION_H
