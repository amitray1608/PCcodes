//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

int n, m;
vector<vector<int>>adj;
const int INF = 1000000000;
vector<int>vis;

struct Edge{
  int w = INF, to = -1;
};

vector<Edge>mini;

void solve(){
  cin >> n >> m;
  adj.resize(n, vector<int>(n, INF));
  vis.resize(n, false);
  mini.resize(n);
  mini[0].w = 0;
  
  for(int i = 0; i < m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    u--, v--;
    adj[u][v] = c;
    adj[v][u] = c;
  }

  int ans = 0;
  for(int i = 0; i < n; i++) {
    int v = -1;
    for(int j = 0; j < n; j++) {
      if(!vis[j] and (v == -1 or mini[j].w < mini[v].w))
        v = j;
    }

    if(mini[v].w == INF) {
      cout << "NO MST" << endl;
      return;
    }

    vis[v] = true;
    ans += mini[v].w;

    if(mini[v].w != -1)
      cout << v << " " << mini[v].to << endl;

    for(int to = 0; to < n; to++) {
      if(adj[v][to] < mini[to].w) 
        mini[to] = {adj[v][to], v};
    }
  }
  cout << ans << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while(t--){
    //tt++;
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  

/*
6 9
5 4 9
5 1 4
4 1 1
1 2 2
2 6 7
2 3 3
3 6 8
3 4 5
4 2 3
*/