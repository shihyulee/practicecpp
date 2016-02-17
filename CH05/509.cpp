// Check the result of Bessel function

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;
double f(double x);
double root(double x1, double x2, double f1, double f2);
double find_root(double x1, double x2);

int main(){
  double x = find_root(0.0, 3.0);
  cout << "Root is " << x << "\n f(x) at root = " << f(x) << endl;
  return(EXIT_SUCCESS);
}

// Bessel function
double f(double x)
{
  const double a1 = 2.2499997, a2 = 1.2656208, a3 = 0.3163866, a4 = 0.0444479, a5 = 0.0039444, a6 = 0.0002100;
  double term = x/3.0;
  double al_term = term * term;
  double a2_term = al_term * al_term;
  double a3_term = al_term * a2_term;
  double a4_term = al_term * a3_term;
  double a5_term = al_term * a4_term;
  double a6_term = al_term * a5_term;
  return (1.0 - a1 * al_term + a2 * a2_term - a3 * a3_term + a4 * a4_term - a5 * a5_term + a6 * a6_term);
}

// Recursive technique
double root(double x1, double x2, double f1, double f2)
{
  const int max_depth = 50;
  const double x_limit = 1e-5;
  static int depth;
  double estimated_root;
  double x_mid = 0.5 * (x1 + x2);
  if (x2 - x1 <= x_limit){
    cout << "Root found at recursion depth = " << depth << endl;
    estimated_root = x_mid;
  }
  else if (++depth > max_depth){
    cout << "WARNING: maxium limit of " << max_depth << " bisections reached" << endl;
    estimated_root = x_mid;
  }
  else {
    double f_mid = f(x_mid);
    if (f_mid == 0.0){
      estimated_root = x_mid;
    }
    else if (f(x1) * f_mid < 0.0){
      estimated_root = root(x1, x_mid, f1, f_mid);
    }
    else {
      estimated_root = root(x_mid, x2, f_mid, f2);
    }
  }
  return estimated_root;
}

double find_root(double x1, double x2)
{
  double f1 = f(x1);
  double f2 = f(x2);
  if (f1 * f2 > 0.0){
    cout << "Error in find_root(): " << "endpoints have same sign" << endl;
    exit(EXIT_FAILURE);
  }
  if (x2 - x1 > 0.0)
    return root(x1, x2, f1, f2);
  else
    return root(x2, x1, f2, f1);
}
