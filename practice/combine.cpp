
#include <bits/stdc++.h>

using namespace std;
#define int int64_t

vector<int> a;
const int maxn = 3e2 + 1;
int dp[maxn][maxn];

int cost(int i, int k, int j) {
  int res = a[i] + a[k];
  res /= abs(a[i] - a[k]) + 1;
  int ress = a[k + 1] + a[j];
  ress /= abs(a[k + 1] - a[j]) + 1;
  return res + res;
}

int recc(int i, int j) {
  if (i == j) return 0;
  int &ans = dp[i][j];
  if (ans != -1)
    return ans;
  ans = INT_MAX;
  for (int k = i; k < j; k++) { 
    int res = recc(i, k) + recc(k + 1, j) + cost(i - 1, k, j);
    ans = min(res, ans); 
  }
  return ans;
}


void solve() {
  int n; cin >> n;
  a.resize(n);
  for (int &i : a) cin >> i;
  memset(dp, -1, sizeof dp);
  int res = recc(1, n - 1);
  cout << res << '\n';
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite


