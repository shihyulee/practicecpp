#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

int main()
{
  srand(time(0));
  int N_i[10] = {};
  int n = 10000;
  int ni = n/10;
  cout << "All the data: " << endl;

  for (int i = 0; i < n; i++){
    int data = rand() % 1000;
    int j = data / 100;
    N_i[j] += 1;
  }

  // check the data
  for (int i = 0; i < 10;++i)
  {
    cout << "N[" << i << "]= " << N_i[i] << "\t";
    cout << "n[" << i << "]= "<< ni << endl;
  }

  long double chi_squ = 0;
  for (int i = 0; i < 10; ++i)
  {
    chi_squ += 1.* (N_i[i] - ni) * (N_i[i] - ni) / ni*ni;
    cout << "chi-square( sum from 1 to "<< i + 1 << " ): " << chi_squ << endl;
  }
  cout << "chi-square: "<< chi_squ << endl;

  return(EXIT_SUCCESS);
}
