//Amit Kumar
//18BCS2059
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

ll gcd(ll a, ll b) {
  if(b == 0)
    return a;
  return gcd(b, a%b);
}

int main() {
  ll a, b;
  cin >> a >> b;
  ll ans = gcd(a, b);
  cout << ans << endl;
 return 0;
}