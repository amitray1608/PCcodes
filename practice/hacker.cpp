vector<string> mixColors(vector<vector<int>> colors, vector<vector<int>> queries) {
  int n = (int) colors.size();
  vector<vector<int>> r(colors), b(colors), g(colors);
  sort(r.begin(), r.end(), [](const vector<int> &xx, const vector<int> &yy){
    return xx[0] < yy[0];
  });  
  sort(b.begin(), b.end(), [](const vector<int> &xx, const vector<int> &yy){
    return xx[2] < yy[2];
  });
  sort(g.begin(), g.end(), [](const vector<int> &xx, const vector<int> &yy){
    return xx[1] < yy[1];
  });
  vector<int> R(n), B(n), G(n);
  for(int i = 0; i < n; i++) {
    R[i] = r[i][0];
    B[i] = b[i][2];
    G[i] = g[i][1];
  }
  vector<string>ans;
  for(int i = 0; i < (int)queries.size(); i++) {
    int x, y, z, X, Y, Z;
    bool flagr = false, flagb = false, flagg = false; 
    x = queries[i][0], y = queries[i][1], z = queries[i][2];
    int l = lower_bound(R.begin(), R.end(), x) - R.begin();
    int r = upper_bound(R.begin(), R.end(), x) - R.begin();
    cout << l << ' ' << r << endl;
    for(int i = l; i <= r; ii++) {
      if(R[i] == x) {
        if(R[i] == x and r[i][2] == z and r[i][1] == y) {
          ans.push_back("YES");
          continue;
        }
        if(R[i] == x and r[i][1] <= y and r[i][2] <= z) {
          flagr = true;
          X = r[i][0];
          Y = r[i][1];
        }
      }
    }
    
    l = lower_bound(G.begin(), G.end(), y) - G.begin();
    r = upper_bound(G.begin(), G.end(), y) - G.begin();
    cout << l << ' ' << r << endl;
    for(int i = l; i <= r; ii++) {
      if(G[i] == x and G[i][2] == z and G[i][1] == y) {
        ans.push_back("YES");
        continue;
      }
      if(R[i] == x and G[i][1] <= y and G[i][2] <= z) {
        flagr = true;
        X = r[i][0];
        Y = r[i][1];
      }
    }
  }
  return ans;
}
