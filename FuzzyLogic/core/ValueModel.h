#ifndef VALUEMODEL_H
#define VALUEMODEL_H
#include "Expression.h"

namespace core
{
    template <class T>
    class ValueModel : public Expression<T>
    {
        public:
            virtual T Evaluate() const;
            void SetValue(T);
        protected:
        private:
        T value;
    };

    template<class T>
    T ValueModel<T>::Evaluate() const
    {
        return value;
    }

    template<class T>
    void ValueModel<T>::SetValue(T _value)
    {
        value=_value;
    }

}
#endif // VALUEMODEL_H
