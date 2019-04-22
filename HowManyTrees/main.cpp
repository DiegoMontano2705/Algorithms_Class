//Problem E
//Given n(nodes), we want to know how many binary trees we can make with these amount of nodes.
//Used Catalan number :      (2n)!
//                          -------
//                          (n+1)!n!
#include <iostream>

using namespace std;

unsigned long long int factorial(unsigned long long int n){
    if (n <= 1)
      return 1;
   else
      return n*factorial(n-1);
}

int main()
{
    unsigned long long int n;
    unsigned long long int a,b,c,ans;
    cin >> n;
    a = factorial(2*n);
    b = factorial(n+1);
    c = factorial(n);
    b = (b*c);
    ans = a/b;
    cout << ans << " BTrees" << endl;

    return 0;
}
