#include <iostream>
#include <cmath>
using namespace std;
main()
{
    double x = 1.;
    double c = 0.;
    int n = 0;
    int k = 0;
    cout << " Put the n value: " << endl;
    cin >> n;
    cout << " Put the c value: " << endl;
    cin >> c;
    cout << " Put the iteration times: "<< endl;
    cin >> k;
    for ( int i = 1; i <= k; i++){
        x = ((n-1)*x)/n + c/(n * pow(x,n-1));
        cout << "iteration times: " << i <<" ,x= " << x << endl;
    }


}
