// use: Implements array class

#include "array.hpp"

int Array::_total = 0; //Included to demonstrate technique.
                      // (Default is 0)

Array::Array(int size)
{
  _elements = size;
  pt = new double[_elements];
  ++_total;
}

Array &Array::operator[](const Array &s)
{
  _elements = s._size;
  pt = new double[_elements];
  ++_total;

  for(int i=0; i < _elements; i++){
    pt[i] = s.pt[i];
  }
  return *this;
}

int Array::NumberOfArrays(void)
{
  return _total;
}
