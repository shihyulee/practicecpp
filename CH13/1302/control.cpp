// Implements controller class

#include <iostream>
#include <cstdlib>
#include "control.hpp"
using namespace std;

controller::controller(double set_max_data, const String &set_label, int set_scale_length)
{
  if (set_max_data <= 0.0){
    cerr << "Maximum input to a controller " << "must be positive." << endl;
    exit(EXIT_FAILURE);
  }
  max_data = set_max_data;
  label = set_label;
  scale_length = set_scale_length;
  data = 0.0; // Default initial value
}
controller &controller::operator=(const controller &c)
{
  max_data = c.max_data;
  label = c.label;
  scale_length = c.scale_length;
  return *this;
}

  /******************************************
  The following function displays the value of data on an analogoue scale.
  The cursor is set by the input() function:
               -------------
               |     *     |
               -------------
  *******************************************/

void controller::display(void)
{
  cout << endl;
  // Draw upper edge:
  int i;
  for (i =- 2; i <= scale_length; ++i){
    cout << "-";
  }

  // Draw left edge:
  cout << "\n|";
  // Step to cursor position:
  for (i = 0; i < cursor; ++i){
    cout << " ";
  }
  // Draw cursor:
  cout << "*";
  // Step to right edge:
  while (i++ < scale_length){
    cout << " ";
  }
  // Draw right edge:
  cout << "|" << endl;
  // Draw lower edge:
  for (i =- 2; i <= scale_length; ++i){
    cout << "-";
  }
  cout << endl;
  // Shift label to centre of display:
  int offset = (scale_length + 3 - label.length()) / 2;
  if (offset < 0){
    offset = 0;
  }
  for (i = 0; i < offset; ++i){
    cout << " ";
  }
  label.print();
  cout << endl;
}
