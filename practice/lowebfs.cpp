
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int n;
    cin >> n;
    vector<string> s(n);
    for (auto &i : s) {
      cin >> i;
    }
    map<string, int> mp;
    map<int, string> pm;
    for (int i = 0; i < n; i++) {
      mp[s[i]] = i;
      pm[i] = s[i];
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n;j ++) {
        adj[i].push_back(j);
        adj[j].push_back(i);
      }
    }

    auto check = [&](int u, int v) {
      string U = pm[u];
      string V = pm[v];
      int N = U.length(), x = 0;
      for(int i = 0; i < N; ++i) {
        x |= (1 << (U[i] - 'A'));
      }
      int m = V.length(), y = 0;
      for(int i = 0; i < m; ++i) {
        y |= (1 << (V[i] - 'A'));
      }
      int count = 0;
      for(int i = 0; i < 26; ++i) {
        if((x & (1 << i)) ^ (y & (1 << i))) {
          count++;
        }
      }
      return count == 1 || count == 2;
    }; 

    int maxi = 0, total = 0;
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++) {
      if (vis[i]) continue;
      queue<int> q;
      total++;
      q.push(i);
      vis[i] = true;
      int count = 0;
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        count++;
        for (auto v : adj[u]) {
          if (vis[v]) continue;
          if (check(u, v)) {
            q.push(v); 
            vis[v] = true;
          }
        }
      }
      maxi = max(maxi, count);
    }
    cout << maxi << ' ' << total << '\n';
  }	
  return 0;
} //Hajimemashite

