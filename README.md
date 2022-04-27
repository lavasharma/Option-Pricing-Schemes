# Option-Pricing-Schemes
Pricing European Options using MCM and FDM schemes built in C++ 

The focus of this small project is to 
    1) Price Options (as the name says!)
    2) Build Numerical Algorithms whose output closely matches that of closed form solutions available for European Options
    3) Learning to build "Clean" and efficient Code using rules of Object Oriented Programming based on C++
    4) Serve a baseline to build and incorporate American Options and more complex Exoitc Options
    
The coding outline for the project is as follows:

![alt text](https://github.com/hobbsquant/Option-Pricing-Schemes/blob/main/Process%20Flow.JPG)

The thick arrows represent a "Has A" relationship meaning that class has a particular instance of the object it is pointed from, while the normal arrows present a "Is A" relationship meaning it is derived from a Base Class. 

Option Pricing using Numerical Methods is typically done in three ways: Finite Difference (FD), Monte Carlo (MC) simulation and numerical integration methods.

Finite Difference Schemes are generally used to discretize and approximate differential equations (using smaller intervals of variables of interest) by specifying 
additional boundary conditions. FDM can be further classified into Implicit and Explicit Schemes. The difference lies in the way of discretization scheme followed. 
For numerical stability of explicit scheme we must ensure that the subdivision of time interval should not go below a given threshold. Small divisons can lead to
accumulation of erros and blow up to produce ivalid results. To overcome this disadvantage we shift to implict scheme that produces numerically stable results. 

Monte Carlo simulation and numerical integration rely on the Feyman-Kac Theorem, whichessentially states that (European) option values can be written as 
discounted expected values of the option’s payoff function at the terminal time T, under the risk-neutral measure. Monte Carlo methods are often employed 
in this context for the valuation of path-dependent high-dimensional options, and also for the computation of all sorts of valuation adjustments in modern 
risk management. However, Monte Carlo methods are typically somewhat slow to converge, and particularly in the context of model calibration this can be an issue.

The sample output, along with times takes for various schemes to run is as follows:

![alt text](https://github.com/hobbsquant/Option-Pricing-Schemes/blob/main/Output.JPG)
