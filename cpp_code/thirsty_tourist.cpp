#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 501;
const int C = 10010;
ll dp[N][C];
pair<ll, ll> ar[N + 1];
int n, h, c;

ll rec(int i, ll w) {
  if(w < 0) return ll(1e18);
  if(i == n) {
    return 0LL;
  }
  ll &res = dp[i][w];
  if(res != -1) return res;
  res = ll(1e18);
  ll diff = ar[i + 1].first - ar[i].first;
  for(ll x = 0; w + x <= c; ++x) {
    res = min(res, x * ar[i].second + rec(i + 1, w + x - diff));
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  assert(false);
  cin >> h >> n >> c;
  memset(dp, -1, sizeof dp);
  for(int i = 0; i < n; ++i) {
    cin >> ar[i].first >> ar[i].second;
  }
  ar[n].first = h;
  sort(ar, ar + n + 1);
  assert(ar[0].first == 0);
  assert(ar[n].first = h);
  ll res = rec(0, 0);
  assert(res != ll(1e18));
  cout << res << '\n';
  return 0;
}
