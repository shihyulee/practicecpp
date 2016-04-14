#include <iostream>
#include <cstdlib>
using namespace std;

class complex {
  friend complex operator+(const complex &u, const complex &v);
  friend double Real(const complex &z);
  friend double Imag(const complex &z);
public:
  double &Real(void);
  double &Imag(void);
  complex(void) { }
  complex(double r, double i);
  complex(const complex &z);
  // Add implicit conversion
  operator double(){
    return _re;
  };


private:
  double _re, _im;
};

inline complex operator+(const complex &u, const complex &v)
{
  return complex(u._re + v._re, u._im + v._im);
}

inline double Real(const complex &z)
{
  return z._re;
}

inline double Imag(const complex &z)
{
  return z._im;
}

inline double &complex::Real(void)
{
  return _re;
}

inline double &complex::Imag(void)
{
  return _im;
}

inline complex::complex(double r, double i)
{
  _re = r;
  _im = i;
}

inline complex::complex(const complex &z)
{
  _re = z._re;
  _im = z._im;
}

void print(const complex &z)
{
  cout << Real(z) << " + i * (" << Imag(z) << ")" << endl;
}

int main()
{
  // complex z1(1, 2), z2(3, 3), z3;
  // z3 = z1 + z2;
  // cout << "z1 + z2 = ";
  // print(z3);

  complex a(1.1, 0);
  cout << "a = "<< endl;
  print(a);
  cout << "a + 1.0 = " << a + 1.0 << endl;

  return(EXIT_SUCCESS);
}
