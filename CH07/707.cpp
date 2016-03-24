#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

// Declaration functions
double newton(double x_lower, double x_upper, double accuracy, double x);
double newton2(double x_lower, double x_upper, double accuracy, double x);
double f_a(double x);
double f_a_D(double x);
double f_b(double x);
double f_b_D(double x);

int main()
{
  cout << "The root of function (a) is:" << endl;
  double x = 0;
  double accuracy = 0.1;

  cout << newton(1.0, 2.0, accuracy, x) << endl;

  cout << "The root of function (b) is:" << endl;
  double y = M_PI/4.0;
  double accuracy2 = 0.01;

  cout << newton2(0.0, M_PI/2.0, accuracy2, y) << endl;

}

// function for Newton-Raphson technique
double newton(double x_lower, double x_upper, double accuracy, double x)
{
  double f = f_a(x);
  double fd = f_a_D(x);
  double value = x - (f / fd);
  if (abs(x - value) >= accuracy)
  {
    return newton(x_lower, x_upper, accuracy, value);
  }

  if(value < x_lower || value > x_upper)
  {
    cout << "The value is beyond the interval" << endl;
  }
  return value;
}

double newton2(double x_lower, double x_upper, double accuracy, double x)
{
  double f = f_b(x);
  double fd = f_b_D(x);
  double value = x - (f / fd);
  if (abs(x - value) >= accuracy)
  {
    return newton(x_lower, x_upper, accuracy, value);
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
  return (1 - sin(x));
}
