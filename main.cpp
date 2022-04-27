#include <iostream>
#include "BSModel.h"
#include "Option.h"
#include "BSE.h"
#include <cmath>
#include "ExplicitMethod.h"
#include "BSEuropean.h"
#include "CNMethod.h"
#include "MonteCarlo.h"
#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{
   double S0=100.0, r=0.049, sigma=0.21;
   double K=100.0, T=1./12., zl=0.0, zu=2.0*S0;
   //BSModel Model(S0,r,sigma);
   //Call EuropeanCall(K,T,zl,zu);

   EurCall call(T,K);
   cout << "Price of Call Option using Closed Form Black Scholes Formula is = " << call.CallPriceByBSFormula(S0, sigma, r) << endl;
   cout << endl;

   BSModel Model(S0,r,sigma);
   Call EuropeanCall(K,T,zl,zu);
   Put EuropeanPut(K,T,zl,zu);
   BSEq BSPDE(&Model,&EuropeanCall);

   int imax=5000, jmax=1000;

   auto start1 = high_resolution_clock::now();
   ExplicitMethod Method(&BSPDE, imax, jmax);
   Method.SolvePDE();
   cout << "Price of Call Option using Explicit Finite Method is = " << Method.v(0.0,S0) << endl;
   auto stop1 = high_resolution_clock::now();
   auto duration1 = duration_cast<microseconds>(stop1 - start1);
   cout << "Time taken by Explicit Method: " << duration1.count() * 1e-6 << " seconds" << endl;
   cout << endl;

    int imax_i= 5000, jmax_i = 1000;

    auto start2 = high_resolution_clock::now();
    CNMethod cnmethod(&BSPDE, imax_i,jmax_i);
    cnmethod.SolvePDE();
    cout << "Price of Call Option using Crank Nicholson (Implicit) Finite Method is = " << cnmethod.v(0.0,S0) << endl;
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    cout << "Time taken by Implicit Method: " << duration2.count() * 1e-6 << " seconds" << endl;
    cout << endl;

    int m = 1000;
    long N = 5000;
    auto start3 = high_resolution_clock::now();
    MonteCarlo mc(&EuropeanCall, m);
    mc.PriceByMC(Model,N);
    cout << "Price of Call Option using Monte Carlo Simulation is = " << mc.Price << endl;
    auto stop3 = high_resolution_clock::now();
    auto duration3 = duration_cast<microseconds>(stop3 - start3);
    cout << "Time taken by Monte Carlo Simulations: " << duration3.count() * 1e-6 << " seconds" << endl;
    cout << endl;

    return 0;
}
