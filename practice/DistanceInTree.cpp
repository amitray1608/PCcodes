#include<bits/stdc++.h>
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
using namespace std;
#define int int64_t
typedef long double dd;
const int MOD = 1e9 + 7;
int k;

class CentroidDecomposition {
 public:
  int ans = 0, N;
  vector<set<int>>adj;
  vector<int> p, sub, dist;
  
  CentroidDecomposition(vector<set<int>>&a) : adj(a) {
    int n = (int)adj.size();
    N = n;
    sub.assign(n+1, 0);
    p.assign(n+1, -1);
    dist.assign(n+1, 0);
    build(1, 0);
  }
  
  void build(int u, int p) {
    int n = subtree(u, p);
    int c = centroid(u, p, n);
    compdist(c, 0, 0, 1);
    int count = 0;
    for(auto i : adj[c]) {
      compdist(i, c, 1, -1);
      count += get(i, c, 1);
      compdist(i, c, 1, 1);
    }
    ans += count/2;
    dist.assign(N, 0);
    for(auto i : adj[c]) {
      if(i != p) {
        adj[i].erase(c); 
        build(i, c);
      }
    }
  }
  
  void compdist(int u, int p, int lv, int val) {
    dist[lv] += val;
    for(auto i : adj[u]) {
      if(i != p)
        compdist(i, u, lv+1, val);
    }
  }

  int subtree(int u, int p) {
    sub[u] = 1;
    for(auto i : adj[u]) if(i != p) {
      sub[u] += subtree(i, u);
    }
    return sub[u];
  } 

  int centroid(int u, int p, int n) {
    for(auto i : adj[u]) {
      if(sub[i] > n/2 and i != p)
        return centroid(i, u, n);
    } 
    return u;
  }

  int get(int u, int p, int l) {
    int counts = 0;
    if(k - l < 0) return counts;
    counts += (k == l ? (dist[k - l] << 1) : dist[k - l]);
    for(auto i : adj[u])
      if(i != p)
        counts += get(i, u, l + 1);
    return counts;
  }
};

void solve(){
  int n;
  cin >> n >> k;
  vector<set<int>>adj(n+1);
  for(int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    //u--, v--;
    adj[u].insert(v);
    adj[v].insert(u);
  }
  CentroidDecomposition d(adj);
  cout << d.ans << endl;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1, tt = 0;
  //cin >> t;
  while(t--){
  //cout << "Case #" << ++t << ": ";
    solve();
  }
  return 0;
}
