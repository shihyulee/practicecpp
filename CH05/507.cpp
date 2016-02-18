// Prime Number problem

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>

using namespace std;

bool test_prime(unsigned n);
void list_prime(unsigned m);

int main(){
  unsigned n;
  cout << "Input a positive number: " << endl;
  cin >> n;
  if (test_prime(n) == 1){
    cout << n << " is a prime number." << endl;
  }
  else {
    cout << n << " is not a prime number." << endl;
  }
  
  list_prime(n);

return 1;
}

bool test_prime(unsigned n)
{
  bool test = true;
  for (unsigned i = 2; i < n; i++){
    if (n % i == 0){
    test = false;
    break;
    }
  }
  return test;
}

void list_prime(unsigned m)
{
  int count = 0;
  cout << "The prime numbers less than or equal to " << m << " have: " << endl;
  for (unsigned i = 2; i <= m; i++){
    if (test_prime(i) == 1){
      cout << i << " ";
      count++;
    }
  }
   cout << endl << endl;
   cout << "The total number of prime lists is: " << count << endl << endl;
}
