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
  if (unit == 'c'){
    if (temp > -273.15){
      cout << temp << " degree C = " << CtoF(temp)<< " degree F."<< endl;
    }
    else{
      cout << " ERROR. The input under absolute zero." << endl;
    }
  } 
    
  else if (unit == 'f'){
    if (temp > -459.67){
      cout << temp << " degree F = " << FtoC(temp)<< " degree C." << endl;
    }
    else{
      cout << " ERROR. The input under absolute zero." << endl;
    }
  }
  else
    cout << "Wrong unit!" << endl;
  return 1;
}

float CtoF(float T)
{ 
  return (T * (9.0f / 5.0f) + 32.0f);  
}

float FtoC(float T)
{ 
  return ((T - 32.0f) * 5.0f/9.0f);  
}