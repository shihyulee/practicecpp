// Defines array class
#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>
#include <cstdlib>
using namespace std;

class array {
public:
  array(int size);
  array(const array &x);
  virtual ~array() {
    delete _pt;
  }
  array &operator=(const array &x);
  virtual double &operator[](int index);
  virtual bool operator!=(const array &x, const array &y);
  int get_size(void);
protected:
  int _n;
  double *_pt;
};

class checked_array : public array {
public:
  checked_array(int size) : array(size) { }
  double &operator[](int index);
  bool operator!=(const array &x, const array &y);
private:
  void check_bounds(int index);
  void check_ToF(const array &x, const array &y);
};

// inline array class implementations:

inline int array::get_size(void)
{
  return _n;
}

inline double &array::operator[](int index)
{
  return _pt[index - 1];
}

inline bool array::operator!=(const array &x, const array &y)
{
  return !(&x == &y);
}

// inline checked_array class implementations:

inline double &checked_array::operator[](int index)
{
  check_bounds(index);
  return array::operator[](index);
}

inline bool checked_array::operator!=(const array &x, const array &y)
{
  return array::operator!=(&x, &y);
}

inline void checked_array::check_bounds(int index)
{
  if (index < 1 || index > _n){
    cout << "Array index " << index << " out of bounds" << endl;
    exit(EXIT_FAILURE);
  }
}

#endif // ARRAY_HPP
