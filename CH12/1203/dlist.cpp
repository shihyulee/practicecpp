 // Implements doubly linked list class.
#include <iostream>
#include <cstring>
#include "dlist.hpp"

dlist::dlist(void)
{
  _head = 0;
  _tail = 0;
  _cursor = 0;
}

dlist::~dlist()
{
  while (_head != 0) {
    node *pt = _head;
    _head = _head->_next;
    delete pt;
  }
}

void dlist::add_head(void)
{
  node *pt = new node;
  if (_head == 0) {
    _tail = pt;
  }
  else{
    _head->_last = pt;
  }
  pt->_next = _head;
  pt->_last = 0;
  _head = pt;
  _cursor = pt;
}

void dlist::delete_head(void)
{
  if (_head == 0) {
    return;
  }
  node *pt = _head;
  _head = _head->_next;
  if (_head != 0) {
    _head->_last = 0;
  }
  _cursor = _head;
  delete pt;
}

/*
double &SparseVector::Element(int i, int j)
{
  return _pt[(i - 1) * _size2 + (j - 1)];
}
*/

matrix::matrix(matrix &a)
{
  _m = a._m;
  _n = a._n;
  _p = new double[_m * _n];
  memcpy(_p, a._p, _m * _n * sizeof(double));
}

matrix::matrix(int rows, int columns)
{
  _m = rows;
  _n = columns;
  _p = new double[_m * _n];
}


double &matrix::operator()(int i, int j)
{
  return _p[_m * i + j];
}
