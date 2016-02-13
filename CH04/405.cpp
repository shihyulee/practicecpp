#include <iostream>
#include <cmath>
using namespace std;

main()
{
    const double PI = 3.141592653589793;
    int m = 20;
    double sum = 0;
    double x;
    double h = (PI - 0)/m;
    double f0 = sin(0);
    double fm = sin(PI);
    double f = sin(x);
    for(int i = 1; i < m; i++){
        x += h;
        sum += sin(x);
    }
    sum = h * (sum + (f0+fm)/2);
    cout << sum << endl;

}
