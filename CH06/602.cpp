#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

int main()
{
  srand(time(0));
  int N_i[10] = {};
  int n_i[10] = {};
  cout << "All the data: " << endl;
  for (int i = 0; i < 10; ++i)
  {
    int data;
    data = rand()%1000;
    cout << data << endl;
    if (data < 100)
    {
      n_i[0] += data;
      N_i[0]++;
    }
    else if (data < 200)
    {
      n_i[1] += data;
      N_i[1]++;
    }
    else if (data < 300)
    {
      n_i[2] += data;
      N_i[2]++;
    }
    else if (data < 400)
    {
      n_i[3] += data;
      N_i[3]++;
    }
    else if (data < 500)
    {
      n_i[4] += data;
      N_i[4]++;
    }
    else if (data < 600)
    {
      n_i[5] += data;
      N_i[5]++;
    }
    else if (data < 700)
    {
      n_i[6] += data;
      N_i[6]++;
    }
    else if (data < 800)
    {
      n_i[7] += data;
      N_i[7]++;
    }
    else if (data < 900)
    {
      n_i[8] += data;
      N_i[8]++;
    }
    else
    {
      n_i[9] += data;
      N_i[9]++;
    }
  }

// check the data
  for (int i = 0; i < 10;++i)
  {
    cout << "N" << i << ": " << N_i[i] << "\t";
    cout << "n" << i << ": "<< n_i[i] << endl;
  }

  long double chi_squ = 0;
  for (int i = 0; i < 10; ++i)
  {
    chi_squ += static_cast<long double> (N_i[i] - n_i[i]) * (N_i[i] - n_i[i]) / n_i[i];
    cout << "chi-square( sum from 1 to "<< i + 1 << " ): " << chi_squ << endl;
  }
  cout << "chi-square: "<< chi_squ << endl;

  return(EXIT_SUCCESS);
}
