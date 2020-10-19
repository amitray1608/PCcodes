//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

struct Edge {
  int u, v, c;
  void fill(int a, int b, int cc) {
    u = a;
    v = b;
    c = cc;
  }
};

vector<vector<int>>adj;
vector<Edge>e;
vector<int>dis;

void solve(){
  int n, m;
  cin >> n >> m;
  adj.resize(n);
  dis.resize(n, MOD);
  e.resize(m);
  for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
  }
  int s, t, c = 0;
  cin >> s >> t;
  for(int i = 0; i < n; i++) {
    for(auto j : adj[i]) {
      if(adj[i].size() > 1){
        e[c++].fill(i, j, 1);
      } else {
        e[c++].fill(i, j, 0);
      }
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j : adj[i])
      cout << j << ' ';
    cout << endl;
  }
  for(int i = 0; i < m; i++)
    cout << e[i].u << ' ' << e[i].v << ' ' << e[i].c << endl;

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