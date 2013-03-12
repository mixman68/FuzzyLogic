#ifndef UNARYEXPRESSION_H
#define UNARYEXPRESSION_H


namespace core
{
    template <class T>
    class UnaryExpression
    {
        public:
            virtual T Evaluate() const = 0;
        protected:
        private:
    };
}

#endif // UNARYEXPRESSION_H
