#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

int main()
{
  int a[2][3][4];
  for(int i = 0;i < 2; ++i){
    for(int j = 0;j < 3; ++j){
      for(int k = 0; k < 4; ++k){
        a[i][j][k] = (1-i) * (2-j) * (3 - k);
        cout << a[i][j][k] << " ";
      }
    }
  }

  return(EXIT_SUCCESS);
}
