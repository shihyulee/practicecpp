// use Defines array class

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <cstdlib>
using namespace std;

class Array {
public:
  Array(const int &size1, const int &size2);
  Array(const Array &s);
  ~Array(){
    delete [] _pt;
  }
  int GetSize(void);
  int GetRowSize(void){return _size1;};
  int GetColumnSize(void){return _size2;};
  double &Element(int i, int j);
  static int NumberOfArrays(void);
private:
  int _elements, _size1, _size2;
  static int _total;
  double *_pt;
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
  return _pt[(i - 1) * _size2 + (j - 1)]; //*(&pt[0] + (i - 1) * size2 + (j - 1))
}
#endif //ARRAY_H
