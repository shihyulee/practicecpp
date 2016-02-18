/***********************************************
The logistic map:
x_n+1 = c * x_n * (1 - x_n)
where 0 <= x_n <= 1 and 0 < c <= 4
***********************************************/

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;
double f(double x, double c, unsigned n);

int main()
{
  const double c = 3;
  double x;
  unsigned n;
  cout << "Input the initial normzlized population X: (X in (0, 1)) " << endl;
  cin >> x;
  while (x <= 0 || x >= 1){
    cout << " Wrong! The value is over the range in (0, 1)" << endl;
    exit(EXIT_FAILURE);
  }
  cout << "Input the times of generation: " << endl;
  cin >> n;
  for (unsigned i = 1; i <= n; i++){
  cout << "The " << i << " generation:\t" << f(x, c, i) << endl;
  }

    return(EXIT_SUCCESS);
}

// The logistic map dunction
double f(double x, double c, unsigned n)
{
  double next;
  for (unsigned i = 0; i < n; i++){
    next = c * x * (1 - x);
    x = next;
  }
  return next;
}
