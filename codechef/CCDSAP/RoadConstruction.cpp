//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

vector<int>parent, weight;
int maxi = 0, counts = 0;
void fill(int n) {
  counts = n;
  parent.resize(n);
  weight.resize(n, 1);
  for(int i = 0; i < n; i++)
    parent[i] = i;
}

int root(int x) {
  if(parent[x] == x)
    return x;
  return parent[x] = root(parent[x]);
}

void unions(int u, int v) {
  u = root(u);
  v = root(v);
  if (u != v) {
      if (weight[u] < weight[v])
          swap(u, v);
      parent[v] = u;
      weight[u] += weight[v];
      counts--;
  }
  maxi = max({maxi, weight[u], weight[v]});
}

void solve(){
  int n, m;
  cin >> n >> m;
  fill(n);
  for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    unions(u, v);
    cout << counts << ' ' << maxi << endl;
  }
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