//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

vector<vector<int>>adj;
vector<bool> vis;
int n, m;
void DFS(int s) {
  vis[s] = true;
  cout << s << ' ';
  for(int i = 1; i <= n; i++){
    if(!vis[i] and adj[s][i])
      DFS(i);
  }
}

void solve(){
  cin >> n >> m;
  vis.resize(n+1, false);
  adj.resize(n+1, vector<int>(n+1, 0));
  while(m--) {
    int u, v;
    cin >> u >> v;
    adj[u][v] = 1;
    adj[v][u] = 1;
  }

  int count = 0, initail = 0;
  for(int i = 1; i <= n; i++) {
    if(!vis[i]){
      DFS(i);
      initail++;
      cout << "OK " << endl;
    }
    // cout << endl;
    // cout << endl;
  }
  deb(initail);
  for(int i = 1; i <= n; i++) {
  vector<int>copy(n+1);
    for(int j = 1; j <= n; j++) {
      vis[j] = false;
      copy[j] = adj[i][j];
      adj[i][j] = adj[j][i] = 0;
    }
    int nval = 0;
    for(int j = 1; j <= n; j++) {
      if(!vis[j] and j != i) {
        nval++;
        DFS(j);
      }
    }
    deb(nval);
    if(nval > initail)
      count++;
    for(int j = 1; j <= n; j++) {
      adj[i][j] = adj[j][i] = copy[j];
    }
  }
  cout << count << endl;
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
6 7
2 4
2 3
4 3
3 5
1 6
2 1
4 5
*/
