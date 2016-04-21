// Implements doubly linked list class.

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
  else
    _head->_last = pt;
  pt->_next = _head;
  pt->_last = 0;
  _head = pt;
  _cursor = pt;
}

void dlist::delete_head(void)
{
  if (_head == 0)
    return;
  node *pt = _head;
  _head = _head->_next;
  if (_head != 0)
    _head->_last = 0;
  _cursor = _head;
  delete pt;
}

// Add
void SparseVector::SparseVector(const int &index, const double &value)
{
  _index = index;
  _value = value;
}

double SparseVector::SparseVector(const SparseVector &s)
{
  return SparseVector(s._index, s._value);
}
