#include <iostream>
#include <cmath>
using namespace std;
int main(){
  int i = 0;
  double sum = 1.0;
  while (1) {
    sum *= 2 * i++ + 1;
    cout<< "i = "<< i <<" "<< sum << endl;
    if (i == 10 ){
      break;
    }
    
  }
  return 1;
}
