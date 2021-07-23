
#include<bits/stdc++.h>

using namespace std;
vector<vector<int>> cap;

int capLeft(vector<vector<int>> &flow, int f, int t) {
  if (cap[f][t])
    return cap[f][t] - flow[f][t];
  else if (cap[t][f])
    return flow[t][f];
  else return 0;
}

vector<int> pathLeft(vector<vector<int>> &flow) {
  int par = -2;
  int unvis = -1;
  int src = cap.size() - 2;
  int sink = src + 1;
  vector<int> parent(sink + 1, -1);
  parent[src] = par;
  deque<int> q;
  vector<int> path;
  q.push_back(src);
  while (!q.empty()) {
    int i = q.front();
    q.pop_front();
    for (int j = 0; j < cap.size(); j++) {
      if (parent[j] == unvis) {
        if (capLeft(flow, i, j)) {
          if (j == sink) {
            path.push_back(sink);
            int p = i;
            while (p != par) {
              path.push_back(p);
              p = parent[p];
            }
            return path;
          } else {
            parent[j] = i;
            q.push_back(j);
          }
        }
      }
    }
  }
  return path;
}

vector<vector<int>> maxFlow() {
  int src = cap.size() - 2;
  int sink = src + 1;
  vector<vector<int>> flow(sink + 1, vector<int>(sink + 1, 0));
  auto path = pathLeft(flow);
  while (!path.empty()) {
    int mini = cap.size();
    for (int j = 0; j < path.size() - 1; j++) {
      int res = capLeft(flow, path[j + 1], path[j]);
      mini = min(res, mini);
    }
    for (int j = 0; j < path.size() - 1; j++) {
      if(cap[path[j + 1]][path[j]])
        flow[path[j + 1]][path[j]] += mini;
      else
        flow[path[j]][path[j + 1]] -= mini;
    }
    path = pathLeft(flow);
  }
  return flow;
}

int crab() {
  int src = cap.size() - 2;
  int n = src / 2;
  auto flow = maxFlow();
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (flow[src][2 * i] != 0) {
      count += flow[src][2 * i];
    }
  }
  return count;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int n, f, e;
    cin >> n >> f >> e;
    int src = 2 * n;
    int sink = src + 1;
    cap.resize(sink + 1, vector<int>(sink + 1, 0));
    while (e--) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      cap[2 * u][2 * v + 1] = 1;
      cap[2 * v][2 * u + 1] = 1;
      cap[src][2 * u]++;
      cap[src][2 * v]++;
    }
    for (int i = 0; i < n; i++) {
      cap[2 * i + 1][sink] = 1;
      if (cap[src][2 * i] > f)
        cap[src][2 * i] = f;
    }
    cout << crab() << '\n';
    for (int i = 0; i < sink + 1; i++) {
      cap[i].clear();
    }
    cap.clear();
  }	
  return 0;
} //Hajimemashite

