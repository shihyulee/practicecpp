#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

int main()
{
  cout << endl << "Expected Value:" << endl << endl;
  int a[2][3][4];
  for(int i = 0;i < 2; ++i){
    for(int j = 0;j < 3; ++j){
      for(int k = 0; k < 4; ++k){
        a[i][j][k] = (1 - i) * (2 - j) * (3 - k);
        cout << "a[" << i << "][" << j << "][" << k << "] = "<< a[i][j][k] << " | " ;
      }
      cout << endl;
    }
    cout << endl;
  }

  cout << "Comma-seperated lists:" << endl << endl;
  int b[2][3][4] = {
                    { {6, 4, 2}, {3, 2, 1} }
                   };

  for (int i = 0; i < 2; ++i){
    for (int j = 0; j < 3; ++j){
      for (int k = 0; k < 4; ++k){
        cout << "b[" << i << "][" << j << "][" << k << "] = " << b[i][j][k] << " | ";
      }
      cout << endl;
    }
    cout << endl;
  }

  return(EXIT_SUCCESS);
}
