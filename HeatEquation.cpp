#include "HeatEquation.h"
#include <cmath>

HeatEquation::HeatEquation
(BSModel* PtrModel_,Option* PtrOption_)
{
    PtrModel=PtrModel_;
    PtrOption=PtrOption_;
    T=PtrOption->T;
    xl=X(0.0,PtrOption->zl);
    xu=X(0.0,PtrOption->zu);
}

double HeatEquation::f(double x)
{
   return V(T,PtrOption->Payoff(Z(T,x)));
}

double HeatEquation::fl(double t)
{
   return V(t,PtrOption->LowerBoundaryCondition(PtrModel,t));
}

double HeatEquation::fu(double t)
{
   return V(t,PtrOption->UpperBoundaryCondition(PtrModel,t));
}

double HeatEquation::Z(double t,double x)
{
   double r=PtrModel->GetR();
   double sigma=PtrModel->Getsigma();
   double S0=PtrModel->GetS0();
   return S0*exp((r-0.5*sigma*sigma)*t+sigma*x);
}

double HeatEquation::V(double t,double u)
{
   return exp(-PtrModel->GetR()*t)*u;
}

double HeatEquation::X(double t,double z)
{
   double r=PtrModel->GetR();
   double sigma=PtrModel->Getsigma();
   double S0=PtrModel->GetS0();
   return (log(z/S0)-(r-0.5*sigma*sigma)*t)/sigma;
}

double HeatEquation::U(double t,double v)
{
   return exp(PtrModel->GetR()*t)*v;
}
