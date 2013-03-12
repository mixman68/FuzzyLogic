#ifndef EXPRESSION_H
#define EXPRESSION_H

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
