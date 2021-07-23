
#include <bits/stdc++.h>

using namespace std;

template <typename T>
class dsu {
public:
  vector<T> p;
  vector<T> rank;
  int n;

  dsu(int _n) : n(_n) {
    p.resize(n);
    rank.resize(n);
    iota(p.begin(), p.end(), 0);
    fill(rank.begin(), rank.end() , 1);
  }

  inline T get(T x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }

  inline void unite(T x, T y) {
    x = root(x);
    y = root(y);
    if(x != y) {
      if(rank[y] < rank[x]) 
        swap(x, y);
      p[x] = y;
      if(rank[x] == rank[y])
        rank[y]++;
    }
  }
};

using ll = long long;
vector<ll> dist;
vector<pair<ll, ll>> adj;
template <typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
const ll inf = (ll) (1e18);

void dijkstra(int S) {
  ll u , vv , c , w;
  minpq<pair<ll, ll>> Q;
  fill(dist.begin(), dist.end(), inf);
  Q.push({0,S});
  dist[S] = 0;
  while(!Q.empty()){
    u = Q.top().second;
    c = Q.top().first;
    Q.pop();
    if(dist[u] < c){
      continue;
    }
    for(auto i : adj[u]){
      w = i.first;
      vv = i.second;
      if(dist[vv] > dist[u] + w){
        dist[vv] = dist[u] + w;
        Q.push({dist[vv],vv});
      }
    }
  }
}



void solve() {
  
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
  //cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite


