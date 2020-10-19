//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void solve(){
  int n;
  cin >> n;
  if(n&1) {
    cout << -1 << endl;
    return;
  }
  vector<vector<int>> G(n);
  for(int i = 0; i < n-1; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  int ans = 0;
  vector<int>w(n, 0);
  function<void(int, int)> dfs = [&] (int u, int p) {
    w[u] = 1;
    for(int x : G[u]) if(x != p) {
      dfs(x, u);
      w[u] += w[x];
    }
    if(~w[u]&1)
      ans++, w[u] = 0;
  };
  dfs(0, -1);
  cout << ans - 1 << endl;
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