// use Defines array class

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <cstdlib>
using namespace std;

class Array {
public:
  Array(int _size1, int _size2);
  Array(const Array &s);
  ~Array(){
    delete [] pt;
  }
  int GetSize(void);
  double &Element(int i, int j);
  static int NumberOfArrays(void);
private:
  int _elements, _size1, _size2;
  static int _total;
  double *pt;
};

inline int Array::GetSize(void)
{
  return _elements;
}

inline double &Array::Element(int i, int j)
{
  if (i < 1 || i > _size1) {
    cout << "Array index " << i << " out of bounds" << endl;
    exit (EXIT_FAILURE);
  }
  if (j < 1 || j > _size2) {
    cout << "Array index " << j << " out of bounds" << endl;
    exit (EXIT_FAILURE);
  }
  return pt[(i - 1) * _size2 + (j - 1)]; //*(&pt[0] + (i - 1) * size2 + (j - 1))
}
#endif //ARRAY_H
