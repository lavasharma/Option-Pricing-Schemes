#pragma once
#include "BSModel.h"

class Option{
   public:
      double T, zl, zu;
      virtual double Payoff(double z) const = 0;
      virtual double UpperBoundaryCondition (BSModel* PtrModel, double t)=0;
      virtual double LowerBoundaryCondition (BSModel* PtrModel, double t)=0;
};

class Call: public Option{
   public:
      double K;
      Call(double K_, double T_, double zl_, double zu_)
         {K=K_; T=T_; zl=zl_; zu=zu_;}
      double Payoff(double z) const;
      double UpperBoundaryCondition(BSModel* PtrModel, double t);
      double LowerBoundaryCondition(BSModel* PtrModel, double t);
};


class Put: public Option{
   public:
      double K;
      Put(double K_, double T_, double zl_, double zu_)
         {K=K_; T=T_; zl=zl_; zu=zu_;}
      double Payoff(double z) const;
      double UpperBoundaryCondition(BSModel* PtrModel, double t);
      double LowerBoundaryCondition(BSModel* PtrModel, double t);
};


