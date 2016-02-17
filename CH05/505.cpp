#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function declarations:
double f(double x);
double root(double x1, double x2, double f1, double f2);
double root2(double x1, double x2, double f1, double f2);
double find_root(double x1, double x2);
double find_root2(double x1, double x2);

int main()
{
  clock_t start_time = clock();
  double x = find_root(1.0, 2.0);
  clock_t stop_time = clock();

  clock_t start_time2 = clock();
  double y = find_root2(1.0, 2.0);
  clock_t stop_time2 = clock();

  cout << "(Recursion) Root is " << x << "\n f(x) at root = " << f(x) << endl;
  cout << " Time taken of iteration version = " << static_cast<double> (stop_time - start_time) / CLOCKS_PER_SEC << " secs." <<endl<<endl;
  cout << "(Iteration) Root is " << y << "\n f(x) at root = " << f(y) << endl;
  cout << " Time taken of recursion version = " << static_cast<double> (stop_time2 - start_time2) / CLOCKS_PER_SEC << " secs." <<endl<<endl;
  return(EXIT_SUCCESS);
}

double f(double x)
{
  return(exp(x) + pow(2.0, -x) + 2.0 * cos(x) - 6.0);
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

// Iterative technique
double root2(double x1, double x2, double f1, double f2)
{
  const int max_depth = 50;
  const double x_limit = 1e-5;
  double estimated_root;

  for (int i = 0; i < max_depth; i++){
    double x_mid = 0.5 * (x1 + x2);
    if (x2 - x1 <= x_limit){
      cout << "Root found at iteration times = " << i << endl<<endl;
      estimated_root = x_mid;
      break;
    }
    else {
      double f_mid = f(x_mid);
      if (f_mid == 0.0){
	estimated_root = x_mid;
	break;
      }
      else if (f(x1) * f_mid < 0.0){
	x2 = x_mid;
      }
      else {
	x1 = x_mid;
      }
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

double find_root2(double x1, double x2)
{
  double f1 = f(x1);
  double f2 = f(x2);
  if (f1 * f2 > 0.0){
    cout << "Error in find_root(): " << "endpoints have same sign" << endl;
    exit(EXIT_FAILURE);
  }
  if (x2 - x1 > 0.0)
    return root2(x1, x2, f1, f2);
  else
    return root2(x2, x1, f2, f1);
}
