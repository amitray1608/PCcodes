
#include<iostream>
#include<vector>
#include<functional>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < n; i++) {
    int u;
    cin >> u;
    if (u == -1) u = n;
    adj[i].push_back(u);
  }
  int s, d;
  cin >> s >> d;

  vector<bool> vis(n, 0);
  vector<int> dis(n, 0);
  int maxi = 0;
  function<void(int , int )> dfs = [&](int s, int w) {
    vis[s] = true;
    dis[s] += s;
    for (auto i : adj[s]) {
      if (i == n) continue;
      if (vis[i]) {
        maxi = max(maxi, w - dis[i]);
      } else {
        dfs(i, w + i);
      }
    }
  };
  dfs(0, 0);
  cout << maxi << '\n';
  return 0;
} //Hajimemashite

/*
23
4 4 1 4 13 8 8 8 0 8 14 9 15 11 -1 10 15 22 22 22 22 22 21
*/

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

