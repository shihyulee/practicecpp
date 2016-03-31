// use: Implements array class

#include "array.hpp"

int array::total = 0; //Included to demonstrate technique.
                      // (Default is 0)

array::array(int size1, int size2)
{
  elements = size1 * size2;
  row = size1;
  colm = size2;
  pt = new double[elements];

  ++total;
}

array::array(const array &s)
{
  elements = s.size1 * s.size2;
  row = size1;
  colm = size2;
  pt = new double[elements];
  ++total;

  for(int i = 0; i < elements; i++){
    pt[i] = s.pt[i];
  }
}

int array::number_of_arrays(void)
{
  return total;
}
