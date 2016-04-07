// Test complex arithmetic class

#include <iostream>
#include <cstdlib>
#include "complex.hpp"
using namespace std;

void print(const complex &z)
{
  cout << Real(z) << " + i * (" << Imag(z) << ")" << endl;
}

int main()
{
  complex z1(1, 2), z2(3, 3), z3, z4, z5, z6;
  const complex i(0, 1);

  cout << "z1 = ";
  print(z1);
  cout << "z2 = ";
  print(z2);
  cout << "i = ";
  print(i);

  cout << "ADDITION:" << endl;
  z3 = z1 + z2;
  cout << "z1 + z2 = ";
  print(z3);

  cout << "SUBTRUCTION:" << endl;
  z4 = z1 - z2;
  cout << "z1 - z2 = ";
  print(z4);

  cout << "MULTIPULATION:" << endl;
  z5 = z1 * z2;
  cout << "z1 * z2 = ";
  print(z5);

  cout << "DIVISION:" << endl;
  z6 = z1 / z2;
  cout << "z1 / z2 = ";
  print(z6);

cout << endl;

  cout << "1.0 + z1 = ";
  print(1.0 + z1);
  cout << "z1 + 1.0 = ";
  print(z1 + 1.0);

  cout << "1.0 - z1 = ";
  print(1.0 - z1);
  cout << "z1 - 1.0 = ";
  print(z1 - 1.0);

  cout << "2.0 * z1 = ";
  print(2.0 * z1);
  cout << "z1 * 2.0 = ";
  print(z1 * 2.0);

  cout << "2.0 / z1 = ";
  print(2.0 / z1);
  cout << "z1 / 2.0 = ";
  print(z1 / 2.0);

cout << endl;
  z3.Real() = 3.4;
  z3.Imag() = 4.5;
  cout << "Real and imaginary parts assigned: ";
  print(z3);

  cout << "mod(z1) = " << Mod(z1) << endl;

  cout << "conj(z1) = ";
  print(Conj(z1));
  cout << "exp(z1) = ";
  print(Exp(z1));



  return(EXIT_SUCCESS);
}
