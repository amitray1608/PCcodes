
#include<bits/stdc++.h>

using namespace std;
int n, m;
vector<vector<int>> adj, rev;
vector<int> components, order, vis;

void dfs1(int s) {
  vis[s] = true;
  for (int i : adj[s]) {
    if (!vis[i]) dfs1(i);
  }
  order.push_back(s);
}

void dfs2(int s) {
  vis[s] = true;
  components.push_back(s);
  for (int i : rev[s]) {
    if (!vis[i]) dfs2(i);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  cin >> n >> m;
  adj.resize(n);
  rev.resize(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    rev[v].push_back(u);
    adj[u].push_back(v);
  } 
  vis.assign(n, false);
  for (int i = 0; i < n; i++) 
    if (!vis[i]) dfs1(i);

  vis.assign(n, false);
  reverse(order.begin(), order.end());
  int count = 1;
  vector<int> res(n, 0);
  for (int i : order) {
    if (!vis[i]) {
      dfs2(i);
      for (int j : components) {
        res[j] = count;
      }
      count++;
      components.clear();
    }
  }
  cout << count - 1 << '\n';
  for (int i : res) {
    cout << i << ' ';
  } cout << '\n';
  return 0;
} //Hajimemashite

