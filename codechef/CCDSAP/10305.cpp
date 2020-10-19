//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

vector<vector<int> >adj;
vector<int> ans;
vector<bool>vis, vis2; 
bool flag;
void dfs(int s) {
  vis[s] = 1;
  vis2[s] = 1;
  for(auto i : adj[s]) {
    if(!vis[i] and !vis2[i]) {
      dfs(i);
    } else if(vis2[i] and vis[i]){
      flag = true;
      return;
    }
  }
  ans.push_back(s);
  vis2[s] = 0;
}

void solve() {
  int n, m;
  cin >> n >> m;
  // if(n == 0 and m == 0) exit(0);
  adj.resize(n);
  vector<int> ind(n, 0);
  for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
  }
  for(auto i : adj) {
    sort(i.begin(), i.end(), greater<int>());
  }
  vis.resize(n, false);
  vis2.resize(n, false);
  for(int i = 0; i < n; i++)
    if(!vis[i])
      dfs(i);
  if(flag ) {
    cout << "Sandro fails. ";
    return;
  }
  // reverse(ans.begin(), ans.end());
  for(int &i : ans) cout << i+1 << ' ';
  for(int i = 0; i < n; i++)
    adj[i].clear();
  ans.clear();
  vis.clear();
  vis2.clear();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(10);
  int t = 1;
  // cin >> t;
  for(int tt = 1; tt <= t; tt++) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  
