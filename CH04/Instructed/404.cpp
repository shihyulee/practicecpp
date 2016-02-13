#include <iostream>
#include <cmath>
using namespace std;
int main()
{
  double x = 1.;
  double c = 0.;
  int n = 0;
  int k = 0;
  cout << " Put the n value: " << endl;
  cin >> n;
  cout << " Put the c value: " << endl;
  cin >> c;
  cout << " Put the number of iterations: "<< endl;
  cin >> k;
  for ( int i = 0; i < k; i++){
    x = (( n - 1) * x) / n + c/( n * pow(x, n - 1) );
    cout << "iteration times: " << i <<", x= " << x << endl;
  }
}
