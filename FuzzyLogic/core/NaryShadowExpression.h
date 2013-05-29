#ifndef NARYSHADOWEXPRESSION_H
#define NARYSHADOWEXPRESSION_H


#include "NullExpressionException.h"
#include "NaryExpression.h"

namespace core
{
    template <class T>
    class NaryShadowExpression : public NaryExpression<T>
    {
    public:
        NaryShadowExpression();
        NaryShadowExpression(NaryExpression<T>*);
        virtual T Evaluate(std::vector<Expression<T>*> *) const;
        virtual void SetTarget(NaryExpression<T>*);
    protected:
    private:
        NaryShadowExpression<T>* target;
    };

    template<class T>
    NaryShadowExpression<T>::NaryShadowExpression(NaryExpression<T>* _target): target(_target)
    {
    }

    template<class T>
    NaryShadowExpression<T>::NaryShadowExpression()
    {
    }

    template<class T>
    void NaryShadowExpression<T>::SetTarget(NaryExpression<T>* _target)
    {
        target = _target;
    }

    template<class T>
    T NaryShadowExpression<T>::Evaluate(std::vector<Expression<T>*>* o) const
    {
        return target->Evaluate(o);
    }
}

#endif // NARYSHADOWEXPRESSION_H
