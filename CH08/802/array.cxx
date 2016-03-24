// use: Implements array class

#include "array.h"

int array::total = 0; //Included to demonstrate technique.
                      // (Default is 0)

array::array(int size)
{
  elements = size;
  pt = new double[elements];
  ++total;
  delete[] pt;
}

array::array(const array &s)
{
  elements = s.size;
  pt = new double[elements];
  ++total;
  delete[] pt;
}

int array::number_of_arrays(void)
{
  return total;
}
