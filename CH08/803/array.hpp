// use Defines array class

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <cstdlib>
using namespace std;

class array {
public:
  array(int size1, int size2);
  array(const array &s);
  ~array(){
    delete [] pt;
  }
  int get_size(void);
  double &element(int i, int j);
  static int number_of_arrays(void);
private:
  int elements, size1, size2,row, colm;
  static int total;
  double *pt;
};

inline int array::get_size(void)
{
  return elements;
}

inline double &array::element(int i, int j)
{
  if (i < 1 || i > row) {
    cout << "Array index " << i << " out of bounds" << endl;
    exit (EXIT_FAILURE);
  }
  if (j < 1 || j > colm) {
    cout << "Array index " << j << " out of bounds" << endl;
    exit (EXIT_FAILURE);
  }
  return pt[(i - 1) * colm + (j - 1)]; //*(&pt[0] + (i - 1) * size2 + (j - 1))
}
#endif //ARRAY_H
