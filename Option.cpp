
#include "Option.h"
#include <cmath>

double Call::Payoff(double z) const{
   if (K > z) return 0.0;
   return z-K;
}

double Call::UpperBoundaryCondition(BSModel* PtrModel, double t){
   return zu-K*exp(-PtrModel->GetR()*(T-t));
}

double Call::LowerBoundaryCondition(BSModel* PtrModel, double t){
   return zl;
}


double Put::Payoff(double z) const{
   if (K < z) return 0.0;
   return K-z;
}

double Put::UpperBoundaryCondition(BSModel* PtrModel, double t){
   return 0.0;
}

double Put::LowerBoundaryCondition(BSModel* PtrModel, double t){
   return K*exp(-PtrModel->GetR()*(T-t));
}
