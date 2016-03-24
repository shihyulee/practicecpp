// use: Tests array class

#include <iostream>
#include <cstdlib>
#include "array.h"
using namespace std;

int main()
{
  int array_size = 20;

  // Define an object:
  array x(array_size);

  // Access the array size:
  cout << "The array size is " << x.get_size() << endl << endl;

  // Store some data:
  for (int i = 1; i <= array_size; ++i)
    x.element(i) = i * 25.0;

  // Retrieve some data:
  for (int i = 1; i <= array_size; ++i)
    cout << x.element(i) << endl;

  // Define another object:
  array y(array_size);

  // Now repeat the above, using a pointer to an object:
  array *p = &y;

  // Use static member function to get number of objects:
  cout << endl << "Number of arrays initialized is " << array::number_of_arrays() << endl;

  // Access the array size:
  cout << "The array size is " << p->get_size() << endl << endl;

  // Store some data:
  for (int i = 1; i <= array_size; ++i)
    p->element(i) = i * 250.0;

  // Retrieve some data:
  for (int i = 1; i <= array_size; ++i)
    cout << p->element(i) << endl;

// Try to go outside of the array bounds:
  p->element(array_size + 1) = 3.142;

  return(EXIT_SUCCESS);
}
