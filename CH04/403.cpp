#include <iostream>
using namespace std;

int fib(int);
main()
{
    int n;
    int sum1 = 0;
    int sum2 = 0;
    int sum3 = 0;
    cin >> n;
    for (int i = 1; i <= n; i++){
        sum1 += fib(i);
    }
    sum2 = fib(n+2)-1;
    cout << sum1 << endl;
    cout << sum2 << endl;

    sum3 = fib(n)*fib(n)-fib(n-1)*fib(n+1);
    cout << sum3 << endl;
}

int fib(int n){
    int i, first = 1, second = 1, next;
    if ( n == 1 || n == 2){
        next = 1;
    }
    else
    {
        for (i = 1; i<= n-2;i++){
            next = first + second;
            first = second;
            second = next;
        }
    }
    return next;
}
// 1 1 2 3 5 8
