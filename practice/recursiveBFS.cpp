#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

vector<vector<int> >adj;
vector<bool> vis;
int n, m;

void bfs(vector<int> lv){
  if(lv.size() == 0)
    return;
  vector<int> next;
  //print
  for(auto i : lv)
    cout << i << ' ';

  for(auto i : lv) {
    for(auto j : adj[i]) {
      if(!vis[j]) {
        vis[j] = true;
        next.push_back(j);
      }
    }
  }
  bfs(next);
}

int main() {
  cin >> n >> m;
  adj.resize(n);
  vis.resize(n);
  for(int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  vis[0] = true;
  vector<int> x;
  x.push_back(0);
  bfs(x);
  cout << endl;
 return 0;
}
/*
4 5
1 2
2 3
1 4
4 5
2 5
*/