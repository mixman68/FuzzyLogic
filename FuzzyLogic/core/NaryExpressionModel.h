//
//  NaryExpressionModel.h
//  FuzzyLogic
//
//  Created by Clément Raussin on 15/05/13.
//  Copyright (c) 2013 Clément Raussin. All rights reserved.
//

#ifndef __FuzzyLogic__NaryExpressionModel__
#define __FuzzyLogic__NaryExpressionModel__

#include <iostream>
#include "NaryExpression.h"
#include "NullExpressionException.h"
#include <vector>

namespace core
{
    template <class T>
    class NaryExpressionModel : public NaryExpression<T>, public Expression<T>
    {
    public:
        NaryExpressionModel();
        NaryExpressionModel(NaryExpression<T>*, std::vector<Expression<T>*>*);
        virtual T Evaluate() const;
        virtual T Evaluate(std::vector<Expression<T>*>*) const;
        virtual void SetOperateur(NaryExpression<T>*);
        virtual void SetOperands(std::vector<Expression<T>*>*);
    protected:
    private:
        NaryExpression<T>* operateur;
        std::vector<Expression<T>*>* operands;
    };
    
    template <class T>
    NaryExpressionModel<T>::NaryExpressionModel()
    {
    }
    
    template <class T>
    NaryExpressionModel<T>::NaryExpressionModel(NaryExpression<T>* _operateur, std::vector<Expression<T>*>* _operands):
    operands(_operands), operateur(_operateur)
    {
    }
    
    template <class T>
    T  NaryExpressionModel<T>::Evaluate(std::vector<Expression<T>*>* o) const
    {
        if(operateur == NULL)
            throw (NullExpressionException("operator missing"));
        return operateur->Evaluate(o);
    }
    
    template <class T>
    T NaryExpressionModel<T>::Evaluate() const
    {
        if(operands ==NULL)
            throw (NullExpressionException("operand missing"));
        return Evaluate(operands);
    }
    
    template<class T>
    void NaryExpressionModel<T>::SetOperateur(NaryExpression<T>* _operateur)
    {
        operateur=_operateur;
    }
    
    template<class T>
    void NaryExpressionModel<T>::SetOperands(std::vector<Expression<T> *>* _operands)
    {
        operands=_operands;
    }
}


#endif /* defined(__FuzzyLogic__NaryExpressionModel__) */
