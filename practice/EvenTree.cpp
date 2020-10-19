#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef double dd;
const int MOD = 1e9 + 7;
vector<int>child;
vector<vector<int>>adj;

void dfs(int u, int p) {
  for(int i : adj[u]) if(i != p) {
    dfs(i, u);
    child[u] += child[i];
  }
}

void solve(){
  int n, m;
  cin >> n >> m;
  adj.resize(n);
  child.assign(n, 1);
  for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(0, -1);
  int count = 0;
  for(int i = 1; i < n; i++) {
    if(~child[i]&1) count++;
    //cout << child[i] << endl;
  }
  cout << count << endl;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1, tt = 0;
  //cin >> t;
  while(t--){
  //cout << "Case #" << ++t << ": ";
    solve();
  }
  return 0;
}

