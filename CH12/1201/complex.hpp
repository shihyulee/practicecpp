// Defines complex arithmetic class
// Implements inline functions

#ifndef COMPLEX_H
#define COMPLEX_H

#include <cmath>
using namespace std;
class complex {
  friend complex operator+(double x, const complex &v);
  friend complex operator+(const complex &u, double x);
  friend complex operator+(const complex &u, const complex &v);
  friend complex operator-(double x, const complex &v);
  friend complex operator-(const complex &u, double x);
  friend complex operator-(const complex &u, const complex &v);
  friend complex operator*(double x, const complex &v);
  friend complex operator*(const complex &u, double x);
  friend complex operator*(const complex &u, const complex &v);
  friend complex operator/(double x, const complex &v);
  friend complex operator/(const complex &u, double x);
  friend complex operator/(const complex &u, const complex &v);
  friend double Real(const complex &z);
  friend double Imag(const complex &z);
  friend double Mod(const complex &z);
  friend complex Conj(const complex &z);
  friend complex Exp(const complex &z);
public:
  double &Real(void);
  double &Imag(void);
  complex(void) { }
  complex(double r, double i);
  complex(const complex &z);
  complex &operator=(double x);
  complex &operator=(const complex &z);
  complex &operator+=(double x);
  complex &operator+=(const complex &z);
  complex operator-() const;
private:
  double _re, _im;
};

// friend functions:

// ADDITION
inline complex operator+(double x, const complex &v)
{
  return complex(x + v._re, v._im);
}

inline complex operator+(const complex &u, double x)
{
  return complex(u._re + x, u._im);
}

inline complex operator+(const complex &u, const complex &v)
{
  return complex(u._re + v._re, u._im + v._im);
}

// SUBTRUCTION
inline complex operator-(double x, const complex &v)
{
  return complex(x - v._re, v._im);
}

inline complex operator-(const complex &u, double x)
{
  return complex(u._re - x, u._im);
}

inline complex operator-(const complex &u, const complex &v)
{
  return complex(u._re - v._re, u._im - v._im);
}

// MULTIPULATION
inline complex operator*(double x, const complex &v)
{
  return complex(x * v._re, x * v._im);
}

inline complex operator*(const complex &u, double x)
{
  return complex(u._re * x, u._im * x);
}

inline complex operator*(const complex &u, const complex &v)
{
  return complex(u._re * v._re - u._im * v._im, u._im * v._re + u._re * v._im);
  // (a, b) * (c, d) = (a * c - b * d, b * c +a * d)
}

// DIVISION
inline complex operator/(double x, const complex &v)
{
  return complex(x * v._re / (v._re * v._re + v._im * v._im), -x * v._im / (v._re * v._re + v._im * v._im));
}

inline complex operator/(const complex &u, double x)
{
  return complex(u._re / x, u._im / x);
}

inline complex operator/(const complex &u, const complex &v)
{
  return complex((u._re * v._re + u._im * v._im) / (v._re * v._re + v._im * v._im),
  (u._im * v._re - u._re * v._im) / (v._re * v._re + v._im * v._im));
  // (a, b) / (c, d) = ((ac+bd)/(cc+dd), (bc-ad)/(cc+dd))
}

inline double Real(const complex &z)
{
  return z._re;
}

inline double Imag(const complex &z)
{
  return z._im;
}

inline double Mod(const complex &z)
// Modulus of z.
{
  return(sqrt(z._re * z._re + z._im * z._im));
}

inline complex Conj(const complex &z)
// Complex conjugate of z.
{
  return complex(z._re, -z._im);
}

inline complex Exp(const complex &z)
// Exponential function for complex argument.
{
  double temp = exp(z._re);

  return complex(temp * cos(z._im), temp * sin(z._im));
}

// Member functions and operators:
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

inline complex &complex::operator=(double x)
{
  _re = x;
  _im = 0.0;
  return *this;
}

inline complex &complex::operator=(const complex &z)
{
  _re = z._re;
  _im = z._im;
  return *this;
}

inline complex &complex::operator+=(double x)
{
  _re += x;
  return *this;
}

inline complex &complex::operator+=(const complex &z)
{
  _re += z._re;
  _im += z._im;
  return *this;
}

inline complex complex::operator-() const
{
  return complex(-_re, -_im);
}

#endif // COMPLEX_H
