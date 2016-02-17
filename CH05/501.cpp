// The programming will test the taken times of different verisons of factorial function


#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

int factorial(int n); // Iteration version function

int factorialoR(const int &n); //Recursion version function

int main(){
  
  int j;
  cout << "Enter an integer: ";
  cin >> j;
  
  clock_t start_time = clock();
  factorial(j);
  clock_t stop_time = clock();
  cout << " Time taken of iteration version = " << static_cast<double> (stop_time - start_time) / CLOCKS_PER_SEC << " secs. \n";
  cout << j << "! = " << factorial(j) << endl;
  
  
  clock_t start_time2 = clock();
  factorialoR(j);
  clock_t stop_time2 = clock();
  cout << " Time taken of recursion version = " << static_cast<double> (stop_time2 - start_time2) / CLOCKS_PER_SEC << " secs. \n";
  cout << j << "! = " << factorialoR(j) << endl;
  
  return 1;
}

// Iteration version function
int factorial(int n)
{
  int result = 1;
  if (n > 0) {
    do {
      result *= n;
      --n;
    } while (n > 1);
  }
  else if (n < 0) {
    cout << "Error in factorial function:\t argument = " << n << endl;
    exit(EXIT_FAILURE);
  }
  return result;
}

//Recursion version function
int factorialoR(const int &n)
{
  int result;
  if (n == 1 || n == 0)
    result = 1;
  else if (n < 0)
    cout << "Error in factorial function: argument = " << n << endl;
  else
    result = n * factorialoR(n - 1);
  
  return result;
}