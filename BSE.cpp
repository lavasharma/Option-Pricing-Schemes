
#include "BSE.h"
#include <cmath>

BSEq::BSEq(BSModel* PtrModel_,Option* PtrOption_){
   PtrModel=PtrModel_; PtrOption=PtrOption_;
   T =PtrOption->T;
   xl=PtrOption->zl;
   xu=PtrOption->zu;
}

double BSEq::a(double t, double z) {return -0.5*pow(PtrModel->Getsigma()*z,2.0);}
double BSEq::b(double t, double z) {return -PtrModel->GetR()*z;}
double BSEq::c(double t, double z) {return PtrModel->GetR();}
double BSEq::d(double t, double z) {return 0.0;}

double BSEq::f(double z)  {return PtrOption->Payoff(z);}
double BSEq::fl(double t) {return PtrOption->LowerBoundaryCondition(PtrModel,t);}
double BSEq::fu(double t) {return PtrOption->UpperBoundaryCondition(PtrModel,t);}
