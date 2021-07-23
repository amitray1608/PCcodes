
#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e3;
int dp[maxn];
vector<vector<int>> adj;

int dfs(int u, int p) {

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int n;
  cin >> n;
  adj.resize(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  memset(dp, 0, sizeof dp);
  dfs(0, -1);
  cout << dp[0] << '\n';
  return 0;
} //Hajimemashite

