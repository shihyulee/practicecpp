#include <iostream>
#include <cmath>
using namespace std;

int main(){
  const double PI = acos(-1.);
  int m = 3;
  double sum = 0.;
  double x = 0.;
  double h = (PI - 0.)/m;
  double f0 = sin(0.);
  double fm = sin(PI);
  
  for(int i = 1; i < m; i++){
    x += h;
    sum += sin(x);
  }
  sum = h * (sum + ( f0 + fm ) / 2.);
  cout << sum << endl;
}
