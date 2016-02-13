#include <iostream>
#include <cmath>
using namespace std;
int main()
{
  unsigned i = 10;
  i += 1.0e-14;
  double sum = 1;
  while (i != 0){
    sum *= 2. * i-- + 1.;
    cout << sum << endl;
  }
  
  unsigned j = 10;
  j -= 100;
  cout << j << endl;
}
