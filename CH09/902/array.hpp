// use Defines array class

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <cstdlib>
using namespace std;


class Array {
public:
  Array(int size);
  Array &operator=(const Array &s);
  Array &operator+=(const Array &s);
  friend double operator*(const Array &r, const Array &s);

  ~Array(){
    delete [] pt;
  }
  int GetSize(void);
  double &operator[](int i);
  double &operator()(int i);
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
  if (i < 0 || i > _elements-1) {
    cout << "Array index " << i << " out of bounds" << endl;
    exit (EXIT_FAILURE);
  }
  return pt[i];
}


inline double &Array::operator()(int i)
{
  if (i < 1 || i > _elements) {
    cout << "Array index " << i << " out of bounds" << endl;
    exit (EXIT_FAILURE);
  }
  return pt[i - 1];
}

inline double operator*(const Array &r, const Array &s)
{
  if (r._elements != s._elements){
    std::cout << "Error, you tried to compute the dot product of arraies with different size"<<std::endl;
    abort();
  }

  double a = 0.;
  for(int i=0; i < r._elements; i++){
    a += r.pt[i] * s.pt[i];
  }
  return a;
}

#endif //ARRAY_H
