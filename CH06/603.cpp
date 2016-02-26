#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

int main()
{
  int p[4][4];
  for(int i = 0; i < 4; ++i){
    for (int j = 0; j < 4 ;++j)
    {
      cin >> p[i][j];
    }
  }
  cout << "P= " << p[0][0] ;
  for(int i = 1; i < 4; ++i){
    for (int j = 1; j < 4 ;++j)
    {
      cout << " + " << p[i][j] << "*" << "x^" << i << "*" << "y^" << j;
    }
  }
  cout << endl;

  return(EXIT_SUCCESS);
}
