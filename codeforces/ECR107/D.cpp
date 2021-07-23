  vector<vector<int>> adj(k);
  for (int i = 0; i < k; i++) {
    for (int j = i + 1; j < k; j++) {
      adj[i].push_back(j);
      adj[j].push_back(i);
    }
  }
  string s = "";
  vector<vector<bool>> vis(k, vector<bool> (k, false));
  function<void(int)> dfs = [&](int u) {
    s += char ('a' + u);
    if (s.size() == n) return;
    bool ok = false;
    for (int i = 0; i < k; i++) {
      if (!vis[u][i] and i != u) {
        vis[u][i] = true;
        dfs(i); 
        ok = true;
      }
    }
    if (!ok and s.size() != n) dfs(u);
  };
  dfs(0);
  cout << s << '\n';
