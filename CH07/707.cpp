#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

// Declaration functions
double newton(double (*F)(double), double (*F_D)(double), double x_lower, double x_upper, double accuracy, double x);
double f_a(double x);
double f_a_D(double x);
double f_b(double x);
double f_b_D(double x);

int main()
{
  cout << "The root of function (a) is:" << endl;
 
  double accuracy = 0.001;
  cout << newton(f_a, f_a_D, 1.0, 2.0, accuracy, 1.5) << endl;

  cout << "The root of function (b) is:" << endl;
  cout << newton(f_b, f_b_D, 0.0, M_PI/2.0, accuracy, M_PI/4.0) << endl;

}

double newton(double (*F)(double x), double (*F_D)(double x), double x_lower, double x_upper, double accuracy, double x)
{
  double f = F(x);
  double fd = F_D(x);
  double value = x - (f / fd);
  if (abs(x - value) >= accuracy)
  {
    return newton(F, F_D, x_lower, x_upper, accuracy, value);
  }

  if(value < x_lower || value > x_upper)
  {
    cout << "The value is beyond the interval" << endl;
  }
  return value;
}



// function of f_a
double f_a(double x)
{
  return (exp(x) + pow(2.0, -x) + 2.0 * cos(x) - 6.0);
}
// The derivative of f_a
double f_a_D(double x)
{
  return (exp(x) -pow(2.0, -x) * log(2) - 2 * sin(x));
}
//function of f_b
double f_b(double x)
{
  return (x - cos(x));
}
// The derivative of f_b
double f_b_D(double x)
{
  return (1 + sin(x));
}
