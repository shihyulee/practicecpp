// use: Implements array class

#include "array.h"

int array::total = 0; //Included to demonstrate technique.
                      // (Default is 0)

array::array(int size1, int size2)
{
  elements = size1 * size2;
  pt = new double*[size1];
  for (int i = 0; i < size1; ++i)
    pt[i] = new double[size2];
    
  ++total;
}

int array::number_of_arrays(void)
{
  return total;
}
