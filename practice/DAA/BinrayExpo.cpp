//Amit Kumar
//18BCS2059
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

ll power(ll base, ll n) {
  if(n == 0)
    return 1;
  ll res = power(base, n/2);
  if(n&1)
    return res*res*base;
  else
    return res*res;
}

int main() {
  ll a, b;
  cin >> a >> b;
  ll ans = power(a, b);
  cout << ans << endl;
 return 0;
}