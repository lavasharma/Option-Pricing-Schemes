
#include "BSModel.h"
#include "Option.h"
#include <iostream>
#include <cmath>

using namespace std;

class MonteCarlo{
    public:
       int m;
       double T,Price;
       Option *PtrOption;
       MonteCarlo(Option *PtrOption_, int m_);
       double PriceByMC(BSModel &Model, long N);
};
