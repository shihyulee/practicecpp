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
  while (test_prime(n) == 1){
    cout << n << " is a prime number." << endl;
    break;
  }

  while (test_prime(n) == 0){
    cout << n << " is not a prime number." << endl;
    break;
  }
  list_prime(n);

return 1;
}

bool test_prime(unsigned n)
{
  int test = 1;
for (int i = 2; i < n; i++){

  if (n % i == 0){
    test = 0;
    break;
  }
  else
    test = 1;
  }
return test;
}

void list_prime(unsigned m)
{
  int count = 0;
  cout << "The prime numbers less than or equal to " << m << " have: " << endl;
  for (int i = 2; i <= m; i++){
    while (test_prime(i) == 1){
      cout << i << " ";
      count++;
      break;
    }
  }
   cout << endl << endl;
   cout << "The total number of prime lists is: " << count << endl << endl;
}
