
#include<bits/stdc++.h>

using namespace std;
using ll = long long;
map<ll, bool> mp;
ll n, a, b;
 
bool recc (ll x) {
  if (x == 0) return true;
  if (mp.find(x) != mp.end())
    return mp[x];
  if (x) {
    if (x == 1) return true;
    return mp[x] = ((a > 1 and x % a == 0 and recc(x / a)) or recc(x - b));
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    cin >> n >> a >> b;
    if (n == 1 or a == 1 or n % a == 0 or n % b == 1) {
      cout << "Yes" << '\n';
      continue;
    }
    bool ok = recc(n);
    cout << (ok ? "Yes" : "No") << '\n';
  }	
  return 0;
} //Hajimemashite

