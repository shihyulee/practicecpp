// Use dlist class to develop the Sparse Vector

#ifndef DLIST_HPP
#define DLIST_HPP

#include <cstdlib>
using namespace std;

typedef double DATA_TYPE;

class node {
  friend class dlist;
public:
  DATA_TYPE data;
  unsigned index;
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

class matrix {
public:
  matrix(matrix &a);
  matrix(int rows, int columns);
  ~matrix(); // Declares destructor function
  double &operator()(int i, int j);
private:
  double *_p; // Address of data
  int _m, _n; // m x n matrix
};

inline matrix::~matrix() { delete _p; }


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
