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
  int n;
  cin >> n;
  vector<string>str(n);
  for(int i = 0; i < n; i++) {
    cin >> str[i];
  }
  g.resize(n);
  gr.resize(n);
  for(int i = 0 ; i < n; i++) {
    g[i].clear();
    gr[i].clear();
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(str[i][j] == 'Y') {
        g[i].push_back(j);
        gr[j].push_back(i);
      }
    }
  }
  int count = 0;
  vis.resize(n, false);
  for(int i = 0; i < n; i++) {
    if(!vis[i])
      dfs(i);
  }
  for(auto i : order)
    cout << i << ' ';
  cout << endl;
  vis.resize(n, false);
  for(int i = 0; i < n; i++) {
    int x = order[i];
    if(!vis[x]) {
      count++;
      dfs2(x);
    }
    for(auto it : comp)
      cout << it << ' ';
    cout << endl;
    // cout << comp.size() << endl;
    comp.clear();
  }
  cout << count << endl;

  order.clear();
  comp.clear();
}

int main(){
  ios_base::sync_with_stdio(false);
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