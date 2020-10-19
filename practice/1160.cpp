#include<bits/stdc++.h>
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
typedef long double dd;
const int MOD = 1e9 + 7;
int n, q;
vector<int>a, dis;
vector<vector<int>> adj, rev;
vector<bool> vis;
int root;


void dist(int u, int d) {
  vis[u] = true;
  dis[u] = d;
  for(auto &v : adj[u]) {
    if(!vis[v])
      dist(v, d + 1);
  }
}

int dfs(int u) {
  vis[u] = true;
  for(auto &v : adj[u]) {
    if(vis[v]) return root;
    dfs(v);
  }
}

void solve(){
  cin >> n >> q;
  a.resize(n);
  adj.resize(n);
  rev.resize(n);
  dis.resize(n, -1);
  vis.assign(n, false);
  for(int &i : a) cin >> i, i--;
  for(int i = 0; i < n; i++) {
    adj[i].push_back(a[i]);
    rev[a[i]].push_back(i);
  }
  for(int i = 0; i < n; i++) 
    if(adj[i].size() == 0 and !vis[i]) 
     root = dfs(i);
  deb(root);
  vis.assign(n, false);
  dist(root, 0);
  for(int &i : dis) cout << i << ' ';
  while(q--) {
    int u, v;
    cin >> u >> v;
    cout << "OK" << endl;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1, tt = 0;
  //cin >> t;
  while(t--){
  //cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
}//Hajimemashite
