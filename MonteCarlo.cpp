#include "MonteCarlo.h"
#include "BSModel.h"
#include <cmath>
#include <iostream>
#include <cmath>

using namespace std;

MonteCarlo :: MonteCarlo(Option *PtrOption_, int m_)
{
    PtrOption = PtrOption_;
    m = m_;
    T = PtrOption->T;
}
double MonteCarlo :: PriceByMC(BSModel &Model, long N)
{
    double H = 0.0;
    SamplePath S(m);
    for(long i = 1; i < N ; i++ )
    {
        Model.GenerateSamplePath(T,m,S);
        H += PtrOption->Payoff(S[S.size()-1]);
    }
    Price = std::exp(-Model.GetR() * T) * (H / N) ;
    return Price;

}


