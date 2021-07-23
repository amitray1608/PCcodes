
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, m, c;
vector<ll> a;

void update(ll p, ll x) {
  while (p <= n) {
    a[p] += x;
    p += (p & -p);
  }
}

void range(ll l, ll r, ll x) {
  update(l, x);
  update(r + 1, -x);
}

ll query(ll p) {
  ll sum = 0; 
  while (p > 0) {
    sum += a[p];
    p -= (p & -p);
  }
  return sum;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  cin >> n >> m >> c;
  a.resize(n + 1, 0);
  for (ll i = 1; i <= n; i++) 
    range(i, i, c);

  while (m--) {
    char t; cin >> t;
    if (t == 'Q') {
      ll p;
      cin >> p;
      cout << query(p) << '\n';
    } else {
      ll l, r, d;
      cin >> l >> r >> d;
      range(l, r, d);
    }
  }
  return 0;
} //Hajimemashite

