#include<bits/stdc++.h>
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
typedef long double dd;
const int MOD = 1e9 + 7;

vector<vector<int>> adj;
vector<int> lev;

ll mpow(ll x, ll n) {
  ll ans = 1;
  while (n != 0) {
    if (n & 1) ans = ans * x % MOD;
    x = 1LL * x * x % MOD;
    n >>= 1;
  }
  return ans;
}

void dfs(int s, int p, int dep) {
  lev[dep]++;
  for(auto &i : adj[s]) if(p != i){
    dfs(i, s, dep+1);
  }
}

void solve(){
  int n, b; // n -> no of nodes, b = level coloring starts
  cin >> n >> b;
  //originally a edge list was given but here i am taking 
  //input as a adjcency list.
  //give is a tree
  adj.resize(n);
  lev.resize(n, 0);
  for(int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[v].push_back(u);
    adj[u].push_back(v);
  }
  dfs(0, -1, 0);
  int nodes = 0;
  for(int i = 0; i < b; i++)
    nodes += lev[i];
  ll ans = mpow(2, nodes);
  cout << ans << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1, tt = 0;
  //cin >> t;
  while(t--){
  //cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
}//Hajimemashite
