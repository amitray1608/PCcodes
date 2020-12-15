#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll nChoosek( ll n, ll k ){
    if (k > n) return 0;
    if (k * 2 > n) k = n-k; 
    if (k == 0) return 1;

    ll result = n;
    for(ll i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}


int main() {
  ll n;
  cin >> n;
  n--;
  ll ans = nChoosek(n, (ll)11);
  cout << ans << '\n';
  return 0;
}
