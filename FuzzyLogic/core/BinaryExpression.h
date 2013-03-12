#ifndef BINARYEXPRESSION_H
#define BINARYEXPRESSION_H


namespace core
{
    template <class T>
    class BinaryExpression
    {
        public:
            virtual T Evaluate() const = 0;
        protected:
        private:
    };
}

#endif // BINARYEXPRESSION_H
