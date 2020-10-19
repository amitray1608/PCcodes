//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void solve() {
  int n;
  cin >> n;
  vector<vector<int> > g(n, vector<int> (n));
  vector<int> deg(n);

  //take g in put;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++)
      deg[i] += g[i][j];
  }

  //To check whether the graph is isolated.

  int first = 0;
  while(first < n and !deg[first])
    ++first;
  if(first == n) {
    cout << -1 << endl;
    return;
  }

  //Find starting and ending node;

  int v1 = -1, v2 = -1;
  bool bad = false;
  for(int i = 0; i < n; i++) {
    if(deg[i]&1) {
      if(v1 == -1) 
        v1 = i;
      else if(v2 == -1)
        v2 = i;
      else
        bad = true;
    }
  }

  // Add an edge to the start and end vertex
  if(v1 != -1) {
    ++g[v1][v2], ++g[v2][v1];
  }

  // DFS to find out the path.
  stack<int>st;
  st.push(first);
  vector<int> res;
  while(!st.empty()) {
    int v = st.top();
    int i;
    for(i = 0; i < n; i++)
      if(g[v][i])
        break;
      if(i == n) {
        res.push_back(v);
        st.pop();
      } else {
        --g[v][i];
        --g[i][v];
        st.push(i);
      }
  }

// Put the path in correct order.

  if(v1 == -1) {
    for(int i = 0; i + 1 < res.size(); ++i) {
      if((res[i] == v[1] and res[i+1] == v2) or (res[i] == v2 and res[i+1] == v1)) {
        vector<int> res2;
        for(int j = i+1; j < res.size(); j++)
          res2.push_back(res[j]);
        for(int j = i; j <= i; j++)
          res2.push_back(res[j]);
        res = res2;
        break;
      }
    }
  }

  //Check for the left edges.
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(g[i][j])
        bad = true;
    }
  }

  if(bad)
    cout << -1 << endl;
  else
    for(auto x : res)
      cout << x << ' ';
}
  

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(10);
  int t = 1;
  // cin >> t;
  for(int tt = 1; tt <= t; tt++) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  
