//Ryuzaki
#include<bits/stdc++.h>
using namespace std;

vector<set<int>> adj2;
vector<vector<int>>adj;
int ecount = 0;
vector<int>vis;

void dfs(int s) {
  vis[s] = 1;
  for(auto i : adj[s]) {
    if(!vis[i]) {
      if(adj2[i].find(s) == adj2[i].end())
        ecount++;
      dfs(i);
    }
  } 
}

void sine() {
  int n;
  cin >> n;
  vector<int>out(n, 0);
  vis.assign(n, 0);
  adj.resize(n);
  adj2.resize(n);
  for(int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    out[u]++;
    adj2[v].insert(u);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int root = 0, maxi = 0;
  for(int i = 0; i < n; i++) {
    if(out[i] > maxi)
      maxi = out[i], root = i;
  }
  //cout << root << endl;
  dfs(root);
  cout << ecount << '\n';
  vis.clear();
  ecount = 0;
  for(int i = 0; i < n; i++)
    adj[i].clear(), adj2[i].clear();
}

int main(){ 
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while(t--) sine();
  return 0;
}
