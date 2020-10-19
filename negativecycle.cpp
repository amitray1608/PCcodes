//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

struct Edge {
    int a, b, cost;
};

int n, m;
vector<Edge> edges;
const int INF = 1000000000;

void solve() {

  cin >> n >> m;
  edges.resize(m);
  for(int i = 0; i < m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    u--, v--;
    edges[i].a = u;
    edges[i].b = v;
    edges[i].cost = c;
  }

  vector<int> d(n);
  vector<int> p(n, -1);
  int x;
  vector<vector<int>>ans(n, INF);
  for(int i = 0; i < n; i++) 
    ans[i][i] = 0;
  
  for (int i = 0; i < n; ++i) {
      x = -1;
      for (Edge e : edges) {
          if (d[e.a] + e.cost < d[e.b]) {
              d[e.b] = d[e.a] + e.cost;
              p[e.b] = e.a;
              x = e.b;
          }
      }
  }

  if (x == -1) {
      cout << "No negative cycle found.";
  } else {
      for (int i = 0; i < n; ++i)
          x = p[x];

      vector<int> cycle;
      for (int v = x;; v = p[v]) {
          cycle.push_back(v);
          if (v == x && cycle.size() > 1)
              break;
      }
      reverse(cycle.begin(), cycle.end());

      cout << "Negative cycle: ";
      for (int v : cycle)
          cout << v << ' ';
      cout << endl;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1, tt = 0;
  cin >> t;
  while(t--){
    tt++;
    cout << "graph " << tt << " ";
    solve();
  }
  return 0;
}  

/*
5 5
0 1 1
1 3 -1
3 4 -1
4 2 1
2 0 -1

4 4
0 1 1
1 2 -1
2 3 -1
3 0 -1

4 5
1 0 4
1 2 -3
2 3 2
3 1 -1
0 2 -1
*/