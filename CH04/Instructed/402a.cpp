#include <iostream>
#include <cmath>
using namespace std;
int main(){
  int sum = 1;
  for (unsigned i = 10; i >= 10; --i)
    sum *= 2 * i + 1;
  
  cout << sum << endl;
  return 1;
}
