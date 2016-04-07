// use: Tests array class

#include <iostream>
#include <cstdlib>
#include "array.hpp"
using namespace std;

int main()
{
  int array_size = 5;

  // Define an object:
  Array x(array_size);

  // Access the array size:
  cout << "The array size is " << x.GetSize() << endl << endl;

  // Store some data:
  for (int i = 1; i <= array_size; ++i)
    x[i] = i * 25.0;

  // Retrieve some data:
  for (int i = 1; i <= array_size; ++i)
    cout << "x[" << i << "] = "<< x[i] << endl;

  // Define another object:
  Array y(array_size);

  // Now repeat the above, using a pointer to an object:
  Array *p = &y;

  // Use static member function to get number of objects:
  cout << endl << "Number of arrays initialized is " << Array::NumberOfArrays() << endl;

  // Access the array size:
  cout << "The array size is " << p->GetSize() << endl << endl;

  // Store some data:
  for (int i = 1; i <= array_size; ++i)
    p->operator[](i) = i * 250.0;

  // Retrieve some data:
  for (int i = 1; i <= array_size; ++i)
    cout << "y[" << i << "] = "<< p->operator[](i) << endl;

  return(EXIT_SUCCESS);
}
