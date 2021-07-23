
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<int>> adj(n);
  vector<int> painted(n, false), c(n);
  for (int &i : c) cin >> i;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> st(1e5 + 1, 0);
  function<void(int, int)> dfs = [&](int s, int p) {
    if (!st[c[s]]) {
      painted[s] = true;
    }
    st[c[s]]++;
    for (int i : adj[s]) {
      if (i == p) continue;
      dfs(i, s);
    }
    st[c[s]]--;
  };
  dfs(0, 0);
  painted[0] = true;
  for (int i = 0; i < n; i++) {
    if (painted[i]) {
      cout << i + 1 << '\n';
    }
  }
  return 0;
} //Hajimemashite

