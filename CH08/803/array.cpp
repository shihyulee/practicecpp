// use: Implements array class

#include "array.hpp"

int Array::_total = 0; //Included to demonstrate technique.
                      // (Default is 0)

Array::Array(const int &size1, const int &size2)
{
  _elements = size1 * size2;
  _size1 = size1;
  _size2 = size2;
  _pt = new double[_elements];

  ++_total;
}

Array::Array(const Array &s)
{
  _elements = s._size1 * s._size2;
  _size1 = s._size1;
  _size2 = s._size2;
  _pt = new double[_elements];
  ++_total;

  for(int i = 0; i < _elements; i++){
    _pt[i] = s._pt[i];
  }
}

int Array::NumberOfArrays(void)
{
  return _total;
}
