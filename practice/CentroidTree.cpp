//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

//solution:
set<int> adj[100'001];
int sub[100'001], parent[100'001];

int subtree(int u, int p) {
  sub[u] = 1;
  for(auto v: adj[u]) if(v != p) {
    sub[u] += subtree(v, u);
  }
  return sub[u];
}

int centroid(int n, int u, int p) {
  for(auto v: adj[u]) if(v != p) {
    if(sub[v] > (n >> 1)) return centroid(n, v, u);
  }
  return u;
}

void decompose(int u, int p) {
  subtree(u, p);
  int c = centroid(sub[u], u, p);
  parent[c] = p;
  for(auto v: adj[c]) {
    adj[v].erase(c);
    decompose(v, c);
  }
}

void hike() {
  int n; cin >> n;
  for(int i = 1; i < n; ++i) {
    int u, v; cin >> u >> v;
    adj[u].insert(v);
    adj[v].insert(u);
  }
  decompose(1, 0);
  // for(int i = 1; i <= n; ++i) {
  //   cout << i << ": " << parent[i] << "\n";
  // }
  for(int i = 1; i <= n; ++i) {
    cout << i << ' ' << parent[i] << "\n";
  }
}
