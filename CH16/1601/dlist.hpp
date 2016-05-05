// Declares doubly linked list and node classes.

#include <cstdlib>
using namespace std;

template<class T> class dlist;

template<class T>class node {
  friend class dlist<T>;
public:
  T data;
private:
  node<T> *_next, *_last;
};

template < class T > class dlist{
public:
  dlist(void);
  virtual ~dlist();
  void add_head();
  void delete_head(void);
  node<T> *forward(void);
  node<T> *backward(void);
  void set_cursor_head(void);
  void set_cursor_tail(void);
  node<T> *cursor_position(void);
  
  void print_forward();
  
private:
  node<T> *_head, *_tail, *_cursor;
};

template<class T> node<T> *dlist<T>::forward(void)
{
  node<T> *pt = _cursor;
  if (_cursor != 0)
    _cursor = _cursor->_next;
  return pt;
}

template<class T> node<T> *dlist<T>::backward(void)
{
  node<T> *pt = _cursor;
  if (_cursor != 0)
    _cursor = _cursor->_last;
  return pt;
}

template<class T> void dlist<T>::set_cursor_head(void)
{
  _cursor = _head;
}

template<class T> void dlist<T>::set_cursor_tail(void)
{
  _cursor = _tail;
}

template<class T> node<T> *dlist<T>::cursor_position(void)
{
  return _cursor;
}

template<class T> dlist<T>::dlist(void)
{
  _head = 0;
  _tail = 0;
  _cursor = 0;
}

template<class T> dlist<T>::~dlist()
{
  while (_head != 0) {
    node<T> *pt = _head;
    _head = _head->_next;
    delete pt;
  }
}

template<class T> void dlist<T>::add_head(void)
{
  node<T> *pt = new node<T>;
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

template<class T> void dlist<T>::delete_head(void)
{
  if (_head == 0)
    return;
  node<T> *pt = _head;
  _head = _head->_next;
  if (_head != 0)
    _head->_last = 0;
  _cursor = _head;
  delete pt;
}

template<class T> void  dlist<T>::print_forward()
{
  node<T> *pt;
  set_cursor_head();
  cout << "forward list: ";
  if((pt = forward()) != 0)
    cout << pt->data;
  else
    cout << "empty";
  while((pt = forward()) != 0)
    cout << " -> " << pt->data;
  cout << endl;
}
