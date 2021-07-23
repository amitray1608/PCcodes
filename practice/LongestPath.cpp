
#include<bits/stdc++.h>

using namespace std;
int n;
vector<vector<int>> adj;
int maxi = 0;
vector<bool> vis;
vector<int> col, dis;

void dfs(int s) {
  vis[s] = true;
  dis[s] = col[s];
  int one = 0, two = 0;
  for (int v : adj[s]) {
    if (!vis[v]) {
      dfs(v);
      if (dis[v] > one) {
        two = one;
        one = dis[v];
      } else if (dis[v] > two) {
        two = dis[v];
      }
    }
  }
  if (col[s]) {
    dis[s] = max(one, two) + 1;
    maxi = max(maxi, one + two + 1);
  } else {
    maxi = max(maxi, max(one, two));
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  cin >> n;
  adj.resize(n);
  vis.resize(n, false);
  col.resize(n, 0);
  dis.resize(n, 0);
  for (int &i : col) {
    cin >> i;
  }
  for (int i = 0; i < n - 1; i++) {
    int u;
    cin >> u;
    u--;
    adj[u].push_back(i + 1);
  }
  dfs(0);
  cout << maxi << '\n';
  return 0;
} //Hajimemashite

