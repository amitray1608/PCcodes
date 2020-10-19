//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

vector<vector<int>>g;
vector<int> order;
vector<bool> vis;

void dfs(int s) {
  vis[s] = true;
  for(auto i : g[s]) {
    if(!vis[i]) 
      dfs(i);
  }
  order.push_back(s);
}

void solve() {
  int n, m;
  cin >> n >> m;
  g = vector<vector<int> >(n);
  vector<pair<int,int>> edges;
  for(int i = 0; i < m; i++) {
    int  t, u, v;
    cin >> t >> u >> v;
    u--, v--;
    if(t) {
      g[u].push_back(v);
    }
    edges.push_back({u, v});
  }

  order.clear();
  vis = vector<bool>(n); 
  for(int i = 0; i < n; i++) {
    if(!vis[i]) dfs(i);
  }
  vector<int> pos(n, 0);
  reverse(order.begin(), order.end());
  for(int i = 0; i < n; i++) {
    pos[order[i]] = i;
  }

  bool bad = false;
  for(int i = 0; i < n; i++) {
    for(auto j : g[i]) {
      if(pos[i] > pos[j]) bad = true;
    }
  }
  if(bad) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
  for(auto i : edges) {
    int x = i.first, y = i.second;
    if(pos[x] < pos[y])
      cout << x+1 << ' ' << y+1 << endl;
    else
      cout << y+1 << ' ' << x+1 << endl;
  }
}



int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(10);
  int t = 1;
  cin >> t;
  for(int tt = 1; tt <= t; tt++) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  

r