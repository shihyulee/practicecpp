// Use dlist class to develop the Sparse Vector

#ifndef DLIST_HPP
#define DLIST_HPP

#include <cstdlib>
using namespace std;

typedef int DATA_TYPE;

class node {
  friend class dlist;
public:
  DATA_TYPE data;
private:
  node *_next, *_last;
};

class dlist {
public:
  dlist(void);
  ~dlist();
  void add_head();
  void delete_head(void);
  node *forward(void);
  node *backward(void);
  void set_cursor_head(void);
  void set_cursor_tail(void);
  node *cursor_position(void);
private:
  node *_head, *_tail, *_cursor;
};

class SparseVector : public dlist {
public:
  SparseVector(const int &index, const int &value);
  SparseVector(const SparseVector &s);
  friend double operator*(const SparseVector &r, const SparseVector &s);
private:
  node *_index, *_value;
};

inline node *dlist::forward(void)
{
  node *pt = _cursor;
  if (_cursor != 0)
    _cursor = _cursor->_next;
  return pt;
}

inline node *dlist::backward(void)
{
  node *pt = _cursor;
  if (_cursor != 0)
    _cursor = _cursor->_last;
  return pt;
}

inline void dlist::set_cursor_head(void)
{
  _cursor = _head;
}

inline void dlist::set_cursor_tail(void)
{
  _cursor = _tail;
}

inline node *dlist::cursor_position(void)
{
  return _cursor;
}

#endif // DLIST_HPP
