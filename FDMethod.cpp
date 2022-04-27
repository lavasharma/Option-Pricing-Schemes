
#include "FDMethod.h"

FDM::FDM(ParabolicPDE* PtrPDE_, int imax_, int jmax_){
   PtrPDE=PtrPDE_;
   imax=imax_; jmax=jmax_;
   dx=(PtrPDE->xu - PtrPDE->xl)/jmax;
   dt=PtrPDE->T/imax;
   V.resize(imax+1);
   for (int i=0; i<=imax; i++) V[i].resize(jmax+1);
}

double FDM::v(double t,double x){
   int i = (int)(t/dt);
   int j = (int)((x-PtrPDE->xl)/dx);
   double lambda1 = (t-FDM::t(i))/dt, lambda0 = 1.0-lambda1;
   double omega1 = (x-FDM::x(j))/dx, omega0 = 1.0-omega1;
   return lambda1*omega1*V[i+1][j+1] + lambda1*omega0*V[i+1][j] +lambda0*omega1*V[i][j+1] + lambda0*omega0*V[i][j];
}
