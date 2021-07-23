
#include<bits/stdc++.h>

using namespace std;
#define int int64_t

const int N = 20;
const int maxn = (1 << 20);
int dp[maxn][N];
vector<vector<int>> adj;
int n, m;

int recc(int mask, int i, int s) {

  int &ans = dp[mask][i];
  if (ans != -1) {
    return ans;
  }
  ans = 0;
  for (int j : adj[i]) {
    if (j < s) continue;
    if (__builtin_popcount(mask) > 2 and j == s) {
      ans++; 
    }
    if (!(mask & (1 << j))) {
      ans += recc((mask | (1 << j)), j, s);
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
    adj[v].push_back(u);
  }
  long long res = 0;
  for (int i = 0; i < n; i++) {
    res += recc((1 << i), i, i);
  }
  cout << (res >> 1) << '\n';
  return 0;
} //Hajimemashite

