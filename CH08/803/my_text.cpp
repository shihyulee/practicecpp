// use: Tests array class

#include <iostream>
#include <cstdlib>
#include "array.hpp"
using namespace std;

int main()
{
  int array_row = 4;
  int array_col = 5;
  // Define an object:
  Array x(array_row, array_col);

  // Access the array size:
  cout << "The array size is " << x.GetSize() << " (" << array_row << ", " << array_col << ")" << endl << endl;

  // Store some data:
  for (int i = 1; i <= array_row; ++i)
    for (int j = 1; j <= array_col; ++j)
      x.Element(i,j) = i * 2 * j;

  // Retrieve some data:
  for (int i = 1; i <= x.GetRowSize(); ++i){
    for (int j = 1; j <= x.GetColumnSize(); ++j){
      cout << x.Element(i,j) << "\t";
    }
    cout << endl;
  }

  cout << endl;
  Array y(x);
   // Retrieve some data:
  for (int i = 1; i <= y.GetRowSize(); ++i){
    for (int j = 1; j <= y.GetColumnSize(); ++j){
      cout << y.Element(i,j) << "\t";
    }
    cout << endl;
  }
  
/*  
  // Define another object:
  array y(array_row, array_col);

  // Now repeat the above, using a pointer to an object:
  array *p = &y;
  cout << "The array size is " << p->get_size() << endl << endl;

 // Store some data:
  for (int i = 1; i <= array_row; ++i)
    for (int j = 1; j <= array_col; ++j)
      p->element(i,j) = i * 2 * j;

// Retrieve some data:
  for (int i = 1; i <= array_row; ++i)
    for (int j = 1; j <= array_col; ++j)
      cout << p->element(i,j) << endl;*/

  return(EXIT_SUCCESS);
}
