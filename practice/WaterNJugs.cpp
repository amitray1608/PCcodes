#include<bits/stdc++.h>
using namespace std;
int main(){
    // write your code
    int t;
    cin >> t;
    while(t--) {
    	long long a, b, c;
    	cin >> a >> b >> c;
        if(c > a+b)
            cout << "No" << '\n';
   		else if(c % __gcd(a, b) == 0)
            cout << "Yes" << '\n';
        else
            cout << "No" << '\n';
    }
    return 0;
}
