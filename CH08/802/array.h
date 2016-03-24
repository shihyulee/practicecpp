// use Defines array class

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <cstdlib>
using namespace std;

class array {
public:
  array(int size);
  array(const array &s);
  int get_size(void);
  double &element(int i);
  static int number_of_arrays(void);
private:
  int size;
  int elements;
  static int total;
  double *pt;
};

inline int array::get_size(void)
{
  return elements;
}

inline double &array::element(int i)
{
  if (i < 1 || i > elements) {
    cout << "Array index " << i << " out of bounds" << endl;
    exit (EXIT_FAILURE);
  }
  return pt[i - 1];
}

#endif //ARRAY_H
