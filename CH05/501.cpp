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
  
  int value;
  
  clock_t start_time = clock();
  value = factorial(j);
  clock_t stop_time = clock();
  cout << " Time taken of iteration version = " << static_cast<double> (stop_time - start_time) / CLOCKS_PER_SEC << " secs. \n";
  cout << j << "! = " << value << endl;
  
  
  clock_t start_time2 = clock();
  value = factorialoR(j);
  clock_t stop_time2 = clock();
  cout << " Time taken of recursion version = " << static_cast<double> (stop_time2 - start_time2) / CLOCKS_PER_SEC << " secs. \n";
  cout << j << "! = " << value << endl;
  
  return 1;
}

// Iteration version function
int factorial(int n)
{
  int result = 1;
  if (n > 0) {
    while( n > 1 ){
      result *= n;
      n--;
    }
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
  if (n > 1) // this is the most common case (it goes first)
    result = n * factorialoR(n - 1);
  else if (n >= 0) // these are particular cases ( they go second)
    result = 1;
  else //(these are exceptions, they go last)
    cout << "Error in factorial function: argument = " << n << endl;
    
  return result;
}