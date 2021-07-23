
#include<bits/stdc++.h>

using namespace std;
#define int int64_t

struct Edge {
  int u, v, weight;
  bool operator<(Edge const& other) {
    return weight < other.weight;
  }
};

vector<int> parent, weig;

void make_set(int v) {
    parent[v] = v;
    weig[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (weig[a] < weig[b])
            swap(a, b);
        parent[b] = a;
        if (weig[a] == weig[b])
            weig[a]++;
    }
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int n, m;
  cin >> n >> m;
  vector<Edge> edges;

  int cost = 0;
  vector<Edge> result;
  parent.resize(n);
  weig.resize(n);
  for (int i = 0; i < n; i++)
      make_set(i);

  sort(edges.begin(), edges.end());

  for (Edge e : edges) {
      if (find_set(e.u) != find_set(e.v)) {
          cost += e.weight;
          result.push_back(e);
          union_sets(e.u, e.v);
      }
  }
  return 0;
} //Hajimemashite

