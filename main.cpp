/*
Benchmark taken from "A Review of Multiobjective Test Problems and a Scalable Test Problem Toolkit" by Simon Huband + "minus" version taken from "Many-Objective Problesm Are Not Always Difficult for Pareto Dominance-Based Evolutionary Algorithms" by Hisao Ishibuchi et al.
*/
#include <bits/stdc++.h>
#include "Toolkit/ExampleProblems.h"
#include "Toolkit/TransFunctions.h"
using namespace std;
using namespace WFG::Toolkit;
using namespace WFG::Toolkit::Examples;
using namespace Problems;
int nobj, nvar , k;
void to_minus(vector<double> &y_obj)
{
       for(int i = 0; i < nobj; i++) y_obj[i] = -y_obj[i] + 2.0*(i+1)+1.0;
}
int main()
{
   srand(time(NULL));
   nobj = 3, nvar = 3, k=2; //position variables
   vector<double> y_obj, x_var(nvar);
   for(int i =0; i < 1000000; i++) //random points...
   {
      for(int i = 0; i < nvar; i++) x_var[i] = (rand()/(double)RAND_MAX)*2.0*(i+1.0);
       y_obj = WFG4( x_var, k, nobj);
      //some recent version are known as minus-WFGx from "Many-Objective Problems Are Not Always Difficult for Pareto Dominance-Based Evolutionary Algorithms" by Hisao Ishibuchi.
      to_minus(y_obj);
      for(auto obj:y_obj) cout << obj <<" ";
      cout <<endl;
   }
  return 0;
}

