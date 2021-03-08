
#include <bits/stdc++.h>

using namespace std;

class DSU {
  public:
  vector<int> par;
  vector<int> rank;
  int n;
  DSU() {
    this -> n = 26;
    par.resize(n);
    rank.resize(n, 0);
    iota(par.begin(), par.end(), 0);
  }

  int root(int x) {
    return par[x] = (par[x] == x ? x : root(par[x]));
  }

  void unite(int u, int v) {
    u = root(u);
    v = root(v);
    if (u == v) return;
    if (rank[u] < rank[v])
      swap(u, v);
    par[u] = v;
  }
 
};

void solve() {
  int n;
  cin >> n;
  vector<string> s(n);
  for (string &i : s) cin >> i;
  vector<vector<int>> id(n);
  vector<int> exist(26, 0);
  int ind = 0;
  DSU d;
  for (auto i : s) {
    for (auto j : i) {
      id[ind].push_back(j - 'a');
      exist[j - 'a']++;
    }
//    cout << "OK" << endl;
//    return;
    for (int in = 1; in < (int)id[ind].size(); in++) {
      d.unite(id[ind][in], id[ind][in - 1]);
    }
    ind++;
  }

  int count = 0;
  for (int i = 0; i < 26; i++) {
    if (d.par[i] == i and exist[i]) count++;
  }
  cout << count << '\n';
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


