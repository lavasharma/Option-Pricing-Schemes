
#pragma once

#include "FDMethod.h"

class ExplicitMethod: public FDM{
   public:
      ExplicitMethod(ParabolicPDE* PtrPDE_, int imax_, int jmax_): FDM(PtrPDE_, imax_, jmax_) {}

      double A(int i, int j) {return dt*(b(i,j)/2.0-a(i,j)/dx)/dx;}
      double B(int i, int j) {return 1.0-dt*c(i,j)+2.0*dt*a(i,j)/(dx*dx);}
      double C(int i, int j) {return -dt*(b(i,j)/2.0+a(i,j)/dx)/dx;}
      double D(int i, int j) {return -dt*d(i,j);}

      void SolvePDE();
};

