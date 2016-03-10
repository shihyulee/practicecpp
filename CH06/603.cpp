#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

int main()
{
  // Make array P
  int p[4][4];
  for(int i = 0; i < 4; ++i){
    for (int j = 0; j < 4 ;++j){
      p[i][j]=(i+1)*(j*3)+(2*i+j);
    }
  }
  cout << "P = ";
  for(int i = 0; i < 4; ++i){
    for (int j = 0; j < 4 ;++j) {
      cout << p[i][j] << "*" << "x^" << i << "*" << "y^" << j;
      if( j < 3 ) std::cout << " + ";
    }
    if( i < 3 ) std::cout << " + ";
  }
  cout << endl;

  // Make array Q
  int q[4][4];
  for(int i = 0; i < 4; ++i){
    for (int j = 0; j < 4 ;++j){
      q[i][j]=(i+1)*(j+1);
    }
  }
  cout << "Q = ";
  for(int i = 0; i < 4; ++i){
    for (int j = 0; j < 4 ;++j) {
      cout << q[i][j] << "*" << "x^" << i << "*" << "y^" << j;
      if( j < 3 ) std::cout << " + ";
    }
    if( i < 3 ) std::cout << " + ";
  }
  cout << endl;

  cout << "Sum = ";
  for(int i = 0; i < 4; ++i){
    for (int j = 0; j < 4 ;++j) {
      cout << p[i][j] +q[i][j] << "*" << "x^" << i << "*" << "y^" << j;
      if( j < 3 ) std::cout << " + ";
    }
    if( i < 3 ) std::cout << " + ";
  }
  cout << endl;

  return(EXIT_SUCCESS);
}
