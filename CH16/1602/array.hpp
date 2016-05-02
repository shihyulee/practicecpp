// Defines array class
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

template<class T> class array {
public:
  array(int size);
  array(const array &x);
  virtual ~array() {
    delete _pt;
  }
  array &operator=(const array &x);
  virtual T &operator[](int index);
  int get_size(void);
protected:
  int _n;
  T *_pt;
};

template<class T> class checked_array : public array<T> {
public:
  checked_array(int size) : array<T>(size) { }
  T &operator[](int index);
private:
  void check_bounds(int index);
};

// inline array class implementations:

template<class T> int array<T>::get_size(void)
{
  return _n;
}

template<class T> T &array<T>::operator[](int index)
{
  return _pt[index - 1];
}

// inline checked_array class implementations:

template<class T> T &checked_array<T>::operator[](int index)
{
  check_bounds(index);
  return array<T>::operator[](index);
}

template<class T> void checked_array<T>::check_bounds(int index)
{
  if (index < 1 || index > array<T>::_n){
    cout << "Array index " << index << " out of bounds" << endl;
    exit(EXIT_FAILURE);
  }
}

template<class T> array<T>::array(int size)
{
  _n = size;
  _pt = new double[_n];
}

template<class T> array<T>::array(const array &x)
{
  _n = x._n;
  _pt = new double[_n];
  memcpy(_pt, x._pt, _n * sizeof(T));
}

template<class T> array<T> &array<T>::operator=(const array &x)
{
  delete _pt;
  _n = x._n;
  _pt = new double[_n];
  memcpy(_pt, x._pt, _n *sizeof(T));
  return *this;
}
