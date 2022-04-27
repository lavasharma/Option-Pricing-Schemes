#pragma once

#include "BSModel.h"
#include "Option.h"
#include "ParabolicPDE.h"

class HeatEquation: public ParabolicPDE
{
   public:
      BSModel* PtrModel;
      Option* PtrOption;
      HeatEquation(BSModel* PtrModel_,Option* PtrOption_);

      double a(double t,double x){return -0.5;}
      double b(double t,double x){return 0.0;}
      double c(double t,double x){return 0.0;}
      double d(double t,double x){return 0.0;}

      double f(double x);
      double fl(double t);
      double fu(double t);

      double Z(double t,double x);
      double V(double t,double u);
      double X(double t,double z);
      double U(double t,double v);
};

