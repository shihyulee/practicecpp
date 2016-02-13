#include <iostream>
#include <cmath>
using namespace std;
main()
{
    int i = 0;
    double sum = 1.0;
    while (1) {
        sum *= 2 * i++ + 1;
        if (i = 10)
        break;
    }
    cout << sum << endl;
}
