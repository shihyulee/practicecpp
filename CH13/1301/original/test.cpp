#include <iostream>
#include <cstdlib>
#include "left_log.hpp"
#include "centre_linear.hpp"
using namespace std;

int main(){
  double x, y, z;

  left_log controller_1(100, "volume", 10);
  cout << endl;
  centre_linear controller_2(100, "balance", 10);
  cout << endl;

  cout << "Input value to be displayed: ";
  cin >> x;
  controller_1.input(x);
  controller_2.input(x);

  controller_1.display();
  controller_2.display();

  controller_1.output(y);
  controller_2.output(z);
  cout << "controller_1 output = " << y << endl << "controller_2 output = " << z << endl;

  return(EXIT_SUCCESS);
}
