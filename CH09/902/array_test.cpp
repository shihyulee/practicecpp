// use: Tests array class

#include <iostream>
#include <cstdlib>
#include <cmath>
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
    x(i) = i * 25.0;

  // Retrieve some data:
  for (int i = 1; i <= array_size; ++i)
    cout << "x(" << i << ") = "<< x(i) << endl;

  // Define another object:
  Array y(array_size); 

  std::cout << std::endl;
    
  
  Array z = x;
  for (int i = 0; i < array_size; ++i)
    cout << "z[" << i << "] = "<< z[i] << endl;
   
  std::cout << std::endl;
  
  z += x;
  for (int i = 0; i < array_size; ++i)
    cout << "z[" << i << "] = "<< z[i] << endl;
  cout << sqrt( x * x )<< endl;
  
  // Now repeat the above, using a pointer to an object:
  Array *p = &y;

  // Use static member function to get number of objects:
  cout << endl << "Number of arrays initialized is " << Array::NumberOfArrays() << endl;

  // Access the array size:
  cout << "The array size is " << p->GetSize() << endl << endl;

  // Store some data:
  for (int i = 1; i <= array_size; ++i)
    (*p)(i) = i * 250.0;

  // Retrieve some data:
  for (int i = 1; i <= array_size; ++i)
    cout << "y(" << i << ") = "<< (*p)(i) << endl;

  return(EXIT_SUCCESS);
}
