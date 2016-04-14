// Implements array class

#include <cstring>  // For memcpy()
#include "array.hpp"
using namespace std;

array::array(int size)
{
  _n = size;
  _pt = new double[_n];
}

array::array(const array &x)
{
  _n = x._n;
  _pt = new double[_n];
  memcpy(_pt, x._pt, _n * sizeof(double));
}

array &array::operator=(const array &x)
{
  delete _pt;
  _n = x._n;
  _pt = new double[_n];
  memcpy(_pt, x._pt, _n *sizeof(double));
  return *this;
}
