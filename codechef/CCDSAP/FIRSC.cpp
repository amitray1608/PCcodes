//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
vector<vector<int>> adj;
vector<bool>vis;

int dfs(int s) {
  vis[s] = true;
  int count = 1;
  for(auto i : adj[s]){
    if(!vis[i]){
      count += dfs(i);
    }
  }
  return count;
}

void solve(){
  int n, m;
  cin >> n >> m;
  adj.resize(n+1);
  vis.resize(n+1, false);
  for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  // for(int i = 1; i <=n; i++){
  //   cout << i << " : ";
  //   for(int j : adj[i])
  //     cout << j << ' ';
  //   cout << endl; 
  // }
  // return;
  int count = 0;
  vector<int>v;
  for(int i = 1; i <= n; i++) {
    if(!vis[i]){
      count++;
       v.push_back(dfs(i));
      }
  }
  ll ans = 1;
  for(int i : v)
    ans = (ans*i)%MOD;
  cout << count << ' ' << ans << endl;
  vis.clear();
  for(int i = 1; i <= n; i++)
      adj[i].clear();
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;//tt = 0;
  cin >> t;
  while(t--){
    // tt++;
    // cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  