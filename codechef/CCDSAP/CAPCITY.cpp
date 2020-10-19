//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

vector<vector<int>>g, gr;
vector<bool>vis;
vector<int>order, comp;

void dfs(int s) {
  vis[s] = true;
  for(auto i : g[s])
    if(!vis[i])
      dfs(i);
  order.push_back(s);
}

void dfs2(int s) {
  vis[s] = true;
  comp.push_back(s);
  for(auto i : gr[s]) 
    if(!vis[i])
      dfs2(i);
}

void solve(){
  int n, m;
  cin >> n >> m;
  g.resize(n);
  gr.resize(n);
  vis.resize(n, false);
  for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    gr[v].push_back(u);
  }

  for(int i = 0; i < n; i++)
    if(!vis[i])
      dfs(i);
  vis.assign(n, false);
  vector<vector<int>>ans;
  for(int i = 0; i < n; i++) {
    int x = order[n-i-1];
    if(!vis[x])
      dfs2(x);
    // debug(comp);
    ans.push_back(comp);
    comp.clear();
  }
  int ind = 0, s = 0;
  for(int i = 0; i < (int)ans.size(); i++) {
    if((int)ans[i].size() > s)
      ind = i, s = (int)ans[i].size();
  }
  sort(ans[ind].begin(), ans[ind].end());
  cout << s << endl;
  for(auto i : ans[ind])
    cout << i+1 << ' ';
  cout << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
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