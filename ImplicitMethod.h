
#include "FDMethod.h"
#include "Matrix.h"

class ImplicitMethod: public FDM
{
   public:
      ImplicitMethod(ParabolicPDE* PtrPDE_,int imax_,int jmax_): FDM(PtrPDE_, imax_, jmax_){}

      virtual double A(int i, int j)=0;
      virtual double B(int i, int j)=0;
      virtual double C(int i, int j)=0;
      virtual double D(int i, int j)=0;
      virtual double E(int i, int j)=0;
      virtual double F(int i, int j)=0;
      virtual double G(int i, int j)=0;

      Vector w(int i);
      Vector A(int i, Vector q);

      Vector LUDecomposition(int i,Vector q);

      void SolvePDE();
};
