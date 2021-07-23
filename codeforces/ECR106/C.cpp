
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
const ll inf = 1e18 + 7;


void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  minpq<array<ll, 2>> pq;
  vector<array<ll, 2>> epos, opos;
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
    pq.push({a[i], i});
    if (~i&1) {
      epos.push_back({a[i], a[i]});
    } else {
      opos.push_back({a[i], a[i]});
    }
  }
  for (int i = 1; i < (int)epos.size(); i++) {
    epos[i][0] = min(epos[i][0], epos[i - 1][0]);
    epos[i][1] += epos[i - 1][1];
  }
   
  for (int i = 1; i < (int)opos.size(); i++) {
    opos[i][0] = min(opos[i][0], opos[i - 1][0]);
    opos[i][1] += opos[i - 1][1];
  }
 
//  while (!pq.empty()) {
//    auto x = pq.top();
//    pq.pop();
//    if (x[1] & 1) {
//      opos.push_back({
//    } else {
//      if (x.first < epos[1]) {
//        epos[1] = x.first;
//        epos[0] = x.second; 
//      }
//    }
//  }
//
  for (int i = 0; i < (int)epos.size(); i++) {
    epos[i][1] += (n - (i + 1)) * epos[i][0];
  }
  
  for (int i = 0; i < (int)opos.size(); i++) {
    opos[i][1] += (n - (i + 1)) * opos[i][0];
  }
  
  long long res = inf;
  for (int i = 1; i < (int)epos.size(); i++) {
    res = min(res, opos[i - 1][1] + epos[i][1]);
  }

  for (int i = 0; i < (int)opos.size(); i++) {
    res = min(res, opos[i][1] +  epos[i][1]);
  }
  cout << res << '\n';
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  ll t = 1;
  cin >> t;
  for (ll tt = 1; tt <= t; ++tt) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite


