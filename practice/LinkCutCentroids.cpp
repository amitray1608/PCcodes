#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef double dd;
const int MOD = 1e9 + 7;

int n;
vector<vector<int>>adj;
vector<int> centroids;
vector<int> sz;
void dfs(int u, int prev) {
  sz[u] = 1;
  bool is_centroid = true;
  for (auto v : adj[u]) if (v != prev) {
    dfs(v, u);
    sz[u] += sz[v];
    if (sz[v] > n / 2) is_centroid = false;
   }
   if (n - sz[u] > n / 2) is_centroid = false;
   if (is_centroid) centroids.push_back(u);
}

void solve(){
  int n;
  cin >> n;
  adj.resize(n);
  sz.resize(n, 0);
  for(int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(0, -1);
  cout << centroids.size() << endl;
  if (centroids.size() == 1) {
    int c = centroids[0];
    cout << c+1 << ' ' << adj[c][0]+1 << endl;
    cout << c+1 << ' ' << adj[c][0]+1 << endl;
  } else if (centroids.size() == 2) {
    int c1 = centroids[0];
    int c2 = centroids[1];
    int x;
    for(int i = 0; i < adj[c1].size(); i++) 
      if(adj[c1][i] != c2) {
        x = adj[c1][i];
        break;
      }
    cout << c1+1 << ' ' << x+1 << endl;
    cout << c2+1 << ' ' << x+1 << endl;
  }
  for(int i = 0; i < n; i++)
    adj[i].clear();
  sz.clear();
  centroids.clear();
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1, tt = 0;
  cin >> t;
  while(t--){
    //tt++;
    //cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
