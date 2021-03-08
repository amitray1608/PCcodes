
#include <bits/stdc++.h>

using namespace std;
#define int int64_t

int n, total;
vector<vector<int>> adj;
vector<int> people, child;

void dfs(int s, int p) {
  child[s] = people[s];
  for (int u : adj[s])
    if (u != p) {
      dfs(u, s);
      child[s] += child[u];
    }
}

void solve() {
  cin >> n;
  adj.resize(n);
  child.resize(n, 0);
  people.resize(n);
  total = 0;
  for (int &i : people)
    cin >> i, total += i;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(0, 0);
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    mp[child[i]]++;
  }
  if (mp.find(0) != mp.end() and mp[0] == n) {
    cout << -1 << '\n';
  } else {
    int count = 0;
    for (auto i : mp) {
      if (i.first == 0) {
        count += ((i.second - 1) * 2);
      } else {
        count += i.second - 1;
      }
    }
    cout << count << '\n';
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
  //cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite


