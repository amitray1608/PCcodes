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
vector<int>tin, low;
vector<bool>vis;
vector<pair<int, int>>ans; 
int timer;

void dfs(int v, int p = -1) {
  vis[v] = true;
  tin[v] = low[v] = timer++;
  for(int to : adj[v]) {
    if(to == p) continue;
    if(vis[to]) {
      low[v] = min(low[v], tin[to]);
    } else {
      dfs(to, v);
      low[v] = min(low[v], low[to]);
      if(low[to] > tin[v]) {
        if(v > to) {
          swap(v, to);
        }
          ans.push_back({v, to});
      }
    }
  }
}

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
  return a.second < b.second;
}

void solve(){
  cin >> n >> m;
  adj.resize(n);
  vis.resize(n, false);
  tin.resize(n, -1);
  low.resize(n, -1);
  for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  timer = 0;
  for(int i = 0; i < n; i++) {
    if(!vis[i])
      dfs(i);
  }
  if(ans.size() == 0)
    cout << "Sin bloqueos" << endl;
  else {
    cout << ans.size() << endl;
    sort(ans.begin(), ans.end(), compare);
    for(auto i : ans)
      cout << i.first+1 << ' ' << i.second+1 << endl;
  } 
  for(int i = 0; i < n; i++)
    adj[i].clear();
  vis.clear();
  tin.clear();
  low.clear();
  ans.clear();
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1, tt = 0;
  cin >> t;
  while(t--){
    tt++;
    cout << "Caso #" << tt << "\n";
    solve();
  }
  return 0;
}  