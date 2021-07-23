
#include<bits/stdc++.h>

using namespace std;

const int N = 12;
const int inf = 1e9;
const int maxn = (1 << N);
int dp[maxn][N];
vector<vector<int>> adj;
int n, m;


int recc(int mask, int i) {
  if (mask == (1 << n) - 1) {
    return dp[0][i] = 0;
  }
  int &ans = dp[mask][i];
  if (ans != -1) {
    return ans;
  }
  ans = INT_MAX;
  for (int j = 0; j < n; j++) {
    if (!(mask & (1 << j)) and i != j and adj[i][j] != inf) {
      ans = min(ans, recc(mask | (1 << j), j) + adj[i][j]);
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  cin >> n >> m;
  adj.resize(n + 1, vector<int>(n + 1, inf));
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    adj[u][v] = w;
    adj[v][u] = w;
  }
  memset(dp, -1, sizeof dp);
  cout << recc(1, 0) << '\n';
  for (int i = 0; i <= 15; i++) {
    for (int j = 1; j <= n; j++) {
      cout << dp[i][j] << ' ';
    } cout << '\n';
  }

  return 0;
} //Hajimemashite

