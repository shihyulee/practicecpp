// \sum_{n=1}^\infty 1 / k^4 = \pi^4 / 90
//
 #include <iostream>
 #include <cmath>
 using namespace std;
 main()
 {
     double sum = 0.;
     double pi;
     for (double i = 1; i <= 5; ++i){
         sum += 1/(i*i*i*i);
     }
     pi = sqrt(sqrt(90*sum));
     cout << pi << endl;
 }
