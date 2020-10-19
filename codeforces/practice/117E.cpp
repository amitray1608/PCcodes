//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

const int mxN=2e5;
int n, m, c[mxN];
vector<int> adj[mxN];
 
void dfs(int u) {
  c[u]=0;
  for(int v : adj[u]) {
    if(~c[v])
      continue;
    dfs(v);
    if(!c[v])
      c[u]=1;
  }
}

void solve() {
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  memset(c, -1, 4*n);
  dfs(0);
  int k=0;
  for(int i=0; i<n; ++i)
    k+=c[i];
  cout << k << "\n";
  for(int i=0; i<n; ++i)
    if(c[i])
      cout << i+1 << " ";
  cout << "\n";
  for(int i=0; i<n; ++i)
    adj[i].clear();

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while(t--){
    //tt++;
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  


