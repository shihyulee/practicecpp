// use Defines array class

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <cstdlib>
using namespace std;

class Array {
public:
  Array(int size);
  Array &operator[](const Array &s);
  ~Array(){
    delete [] pt;
  }
  int GetSize(void);
  double &operator[](int i);
  static int NumberOfArrays(void);
private:
  int _size;
  int _elements;
  static int _total;
  double *pt;
};

inline int Array::GetSize(void)
{
  return _elements;
}

inline double &Array::operator[](int i)
{
  if (i < 1 || i > _elements) {
    cout << "Array index " << i << " out of bounds" << endl;
    exit (EXIT_FAILURE);
  }
  return pt[i - 1];
}

#endif //ARRAY_H
