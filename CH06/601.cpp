// calculate mean, variance and standard deviation

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

int main()
{
  
  double *x;
    
  srand(time(0));

  cout << "Set the number of data : " << endl;
  int num;
  cin >> num;
  
  if ( num < 1) {
    cout << " Error input! " << endl;
    exit(EXIT_FAILURE);
  }
  else {
    x = new double [num];
  }
  
  double sum = 0.;
  
  // store data to array
  for (int i = 0; i < num; ++i){
    x[i] = static_cast < double > ( rand() )/ RAND_MAX ;
    sum += x[i];
    cout << x[i] << " ";
  }
  cout << endl;
  
  // Calculate Mean
  double mean = sum / num;
  cout << "mean: " << mean << endl;

  // Calculate Variance and standard deviation
  double var = 0.;
  for (int i = 0; i < num; ++i){
    var += (mean - x[i]) * (mean - x[i]);
  }
  var = var / (num - 1);
  double sd = sqrt(var);
  cout << "Variance: " << var << endl;
  cout << "Standard Deviation: " <<sd << endl;

  delete [] x;
  
  return(EXIT_SUCCESS);
  
}
