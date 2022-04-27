#pragma once
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef vector<double> SamplePath;

class BSModel
{
   private:
        double S0, r, sigma;
   public:
      BSModel(double S0_, double r_, double sigma_){
        S0 = S0_;
        r = r_;
        sigma = sigma_;
        srand(time(NULL));
    }
      double GetS0() {return S0;}
      double Getsigma() {return sigma;}
      double GetR() {return r;}
      void GenerateSamplePath(double T,int m,SamplePath& S);
};


