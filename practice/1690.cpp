
#include<bits/stdc++.h>

using namespace std;
#define int int64_t

const int MOD = 1e9 + 7;
const int N = 21;
const int maxn = (1 << 20) + 1;
int dp[maxn][N];
int n, m;
vector<vector<int>> adj;

int recc(int mask, int i) {
  if (mask == (1 << n) - 1 and i == n - 1) {
    return 1;
  }
  if (i == n - 1) return 0;
  int &ans = dp[mask][i];
  if (ans != -1) {
    return ans;
  }
  ans = 0;
  for (int j : adj[i]) {
    if (!(mask & (1 << j))) {
      long curr = (ans + recc((mask | (1 << j)), j)) % MOD;
      ans = curr;
    }
  }
  return ans;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  cin >> n >> m;
  adj.resize(n);
  memset(dp, -1, sizeof dp);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
  }
  cout << recc(1, 0) << '\n';
  return 0;
} //Hajimemashite

