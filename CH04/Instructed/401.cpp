// \sum_{n=1}^\infty 1 / k^4 = \pi^4 / 90
//
#include <iostream>
#include <cmath>
using namespace std;
int main(){
  double sum = 0.;
  for (unsigned i = 1; i <= 100; ++i){
    unsigned i2 = i * i;
    unsigned i4 = i2 * i2;
    sum += 1. / i4;
  }
  double pi = sqrt( sqrt(90. * sum) );
  cout.precision(14);
  cout << pi << endl;
 
  return 1;
 }
