// calculate mean, variance and standard deviation

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

int main()
{
  const int max_data = 100;
  int num;
  double data;
  double x[max_data];
  double sum;
  double mean;

  srand(time(0));

  cout << "Put the data number: " << endl;
  cin >> num;

  // store data to array
  if ( num <= 100 && num > 0) {
    for (int i = 0; i < num; ++i){
      data = rand()%100 /100.0;
      x[i] = data;
      sum += data;
      cout << x[i] << " ";
    }
    cout << endl;
  }
  else
  {
    cout << " Error input! " << endl;
    exit(EXIT_FAILURE);
  }
  // Calculate Mean
  mean = sum / num;
  cout << "mean: " << mean << endl;

  // Calculate Variance and standard deviation
  double var, sd;
  for (int i = 0; i < num; ++i){
    var += (mean - x[i]) * (mean - x[i]);
  }
  var = var / (num - 1);
  sd = sqrt(var);
  cout << "Variance: " << var << endl;
  cout << "Standard Deviation: " <<sd << endl;

  return(EXIT_SUCCESS);
}
