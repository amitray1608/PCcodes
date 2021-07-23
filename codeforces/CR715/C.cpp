
#include<bits/stdc++.h>

using namespace std;
using ll = long long;
#define deb(x) cout << #x << " = " << x << endl;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int t = 1;
//  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll &i : a) {
      cin >> i;
    }
    map<ll, ll> mp;
    for (int i = 0; i < n; i++) {
      mp[a[i]]++;
    }
    vector<array<ll, 2>> v;
    for (auto i : mp) {
      array<ll, 2> tmp = {i.second, i.first};
      v.push_back(tmp);
    }
    sort(v.begin(), v.end(), 
        [&](const array<ll, 2> & x, const array<ll, 2> &y) {
          if (x[0] != y[0]) return x[0] > y[0];
          return x[1] < y[1];
        });
    ll sum = 0LL;
    bool vis[n];
    memset(vis, 0, sizeof vis);
    ll maxi = LONG_MIN;
    ll mini = LONG_MAX;
    for (int i = 0; i < n; i++) {
      ll pos = n, req = LONG_MAX;
      for (int j = 0; j < n; j++) {
        if (vis[j]) continue;
        auto [x, y] = v[j];
        maxi = max(maxi, y);
        mini = min(mini, y);
        ll curr = (maxi - mini) * x;
        if (curr < req) {
          req = curr;
          pos = j;
        }
      }
      if (pos != n) vis[pos] = true;
      if (req != LONG_MAX) sum += req;
    }
    cout << sum << '\n';
  }	
  return 0;
} //Hajimemashite

