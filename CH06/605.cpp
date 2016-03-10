#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

int main()
{
  // develop a 5-dim array and assign to the values
  float data[4][4][4][4][4];
  for (int i = 0; i < 4; ++i){
    for (int j = 0; j < 4; ++j){
      for (int k = 0; k < 4; ++k){
        for (int l = 0; l < 4; ++l){
          for (int m = 0; m < 4; ++m){
            data[i][j][k][l][m] = i + j + k + l + m;
          }
        }
      }
    }
  }
  // The FIRST Version
  clock_t start_time = clock();
  float sum = 0;
  float average = 0;
  for (int i = 0; i < 4; ++i){
    for (int j = 0; j < 4; ++j){
      for (int k = 0; k < 4; ++k){
        for (int l = 0; l < 4; ++l){
          for (int m = 0; m < 4; ++m){
            sum += data[i][j][k][l][m];
          }
        }
      }
    }
  }
  average = sum / (4 * 4 * 4 * 4 * 4);
  clock_t stop_time = clock();

  cout << average << endl;
  cout << "Time taken of the FIRST version = " << static_cast<float> (stop_time - start_time) / CLOCKS_PER_SEC << " secs. " << endl;

  // The SECOND Version
  clock_t start_time2 = clock();
  float sum2 = 0;
  float average2 = 0;
  for (int i = 0; i < 4; ++i){
    for (int j = 0; j < 4; ++j){
      for (int k = 0; k < 4; ++k){
        for (int l = 0; l < 4; ++l){
          for (int m = 0; m < 4; ++m){
            sum2 += *(data[0][0][0][0] + 4 * 4 * 4 * 4 * i + 4 * 4 * 4 * j + 4 * 4 * k + 4 * i + m);
          }
        }
      }
    }
  }
  average2 = sum2 / (4 * 4 * 4 * 4 * 4);
  clock_t stop_time2 = clock();

  cout << average2 << endl;
  cout << "Time taken of the SECOND version = " << static_cast<float> (stop_time2 - start_time2) / CLOCKS_PER_SEC << " secs. " << endl;

  return(EXIT_SUCCESS);
}
