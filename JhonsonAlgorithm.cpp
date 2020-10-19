//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
const int INF = 100000000;

void solve(){
  int n, m;
  cin >> n >> m;
  vector<vector<int>>adj(n, vector<int>(n, INF));
  for(int i = 0; i < n; i++) adj[i][i] = 0;
  for(int i = 0; i < m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    u--, v--;
    adj[u][v] = c;
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      for(int k = 0; k < n; k++) {
        if(adj[i][k] < INF and adj[k][k] < 0 and adj[k][j] < INF) {
          adj[i][j] = -INF;
        }
        if(adj[i][k] < INF && adj[k][j] < INF){
          adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
        }
      }
    }
  }


  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(adj[i][j] >= INF)
        cout << "# ";
      else
        cout << adj[i][j] << ' ';
    }
    cout << endl;
  }
}

int main(){
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