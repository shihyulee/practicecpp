// Conversion of units of temperature

#include <iostream> 
#include <cmath>

using namespace std;
float CtoF(float n);
float FtoC(float n);

int main() {
  
  float temp;
  char unit;
  cout << "Please input the temperature: " << endl;
  cin >> temp;
  cout << "Please choose the unit that you input, c or f?" << endl;
  cin >> unit;
  if (unit == 'c')
    cout << temp << " degree C = " << CtoF(temp)<< " degree F."<< endl;
  else if (unit == 'f')
    cout << temp << " degree F = " << FtoC(temp)<< " degree C." << endl;
  else
    cout << "Wrong unit!" << endl;
  return 1;
}

float CtoF(float n)
{ 
  return (n * (9.0 / 5.0) + 32.0);  
}

float FtoC(float n)
{ 
  return ((n - 32.0) * 5.0/9.0);  
}