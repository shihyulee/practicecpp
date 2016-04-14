// Tests array class

#include <iostream>
#include <cstdlib>
#include "array.hpp"
using namespace std;

double sum(array &a, int first_index, int last_index)
{
  double result = a[first_index];
  for (int i = first_index +1; i <= last_index; ++i)
    result += a[i];
  return result;
}

int main()
{
  const int n = 10;

  // Define an object:
  checked_array x(n);

  // Access the array size:
  cout << "The array x has " << x.get_size() << " elements." << endl;

  // Store some data
  // Also find the total directly
  // so it can be used for comparison.
  double total = 0.0;
  for (int i = 1; i <= n; ++i) {
    x[i] = i * 25.0;
    total += i *25.0;
  }

  // Retrieve some data:
  cout << " The data stored in x are:" << endl;
  for(int i = 1; i <= n; ++i)
    cout << x[i] << endl;
  cout << endl;

  // Define another object using copy constructor:
  checked_array y = x;

  // Check the array size:
  cout << "The array y has " << y.get_size() << " elements." << endl
       << "y was created by the copy constructor." << endl << endl;

  // Check that thecopy is identical:
  int errors = 0;
  for (int i = 1; i <= n; ++i)
    if (x[i] != y [i]) {
      cout << "x[" << i << " ] != y[" << i << "]" << endl;
      ++errors;
    }
  if (errors)
    cout << errors << " elements of the arrays x " << "and y differ in their data" << endl;
  else
    cout << "Arrays x and y have identical data" << endl << endl;

  // Define another object with half the size but no bounds
  // checking;
  array z(n/2);

  // Check the array size:
  cout << "The array z has " << z.get_size() << " elements" << endl << endl;

  // Try out the assignment operator:

  z = x;

  // Check the array size:
  cout << "After assignment of x to z, the array z has " << z.get_size() << "  elements." << endl << endl;

  errors = 0;
  // Check that the copy is identical:
  for (int i = 1; i <= n ; ++i)
    if (z[i] != x[i]) {
      cout << "z[" << i << "] != x[" << i << "]" << endl << endl;
      ++errors;
    }
  if (errors)
    cout << errors << " elements of the arrays x and z " << "differ in their data." << endl;
  else
    cout << "Arrays x and z have identical data." << endl << endl;

  // Find sum for z[i], going out of bounds. If you get the
  // correct result, try changing the third argument in sum
  // to something else greater than n:
  cout << "The sum of the data in z is " << sum(z, 1, 2 * n) << " .\nTHe sum should be " << total <<"." << endl << endl;

// Find sum for x[i], going out of bounds:
  cout << "The sum of the data in x is " << sum(x, 1, 2 * n) << " .\nTHe sum should be " << total <<"." << endl << endl;

  return(EXIT_SUCCESS);
}
