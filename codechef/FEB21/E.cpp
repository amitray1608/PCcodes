
#include <bits/stdc++.h>

using namespace std;
#define deb(x) cout << #x << " = " << x << endl;

vector<vector<int>> adj;
int n, q;
vector<int> child;
const int maxn = 1e5 + 1;
unordered_map<int, int> mp[maxn]; 

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

  inline T root(T x) {
    return (x == p[x] ? x : (p[x] = root(p[x])));
  }

  inline void unite(T x, T y) {
    y = root(y);
    p[x] = y;
  }
};

void dfs(int s, int p, dsu<int> &d) {
  if (child[s] == 0) {
    mp[s][1] += 1;
    return;
  }
  int chld = child[s];
  int root = d.root(s);
  for (int &i : adj[s]) {
    int x = i;
    if (chld == 1) {
      x = root;
    }
    dfs(x, s, d);
    for (auto &ii : mp[x]) {
      int div = chld * ii.first;
      mp[s][div] += ii.second;
    }
  }
}

void dfs1(int s, dsu<int> &d) {
  int chld = child[s];
  if (!chld) return;
  for (int &i : adj[s]) {
    dfs1(i, d);
  }
  if (chld == 1) {
    d.p[s] = d.p[adj[s][0]];
  }
}

void solve() {
  cin >> n;
  adj.resize(n);
  child.resize(n, 0);
  dsu<int> d(n);
  for (int i = 0; i < n - 1; i++) {
    int p;
    cin >> p; --p;
    adj[p].push_back(i + 1);
    child[p]++;
  }
  dfs1(0, d);
  dfs(0, 0, d);
//  for (int i = 0; i < n; i++) {
//    for (auto it : mp[i]) {
//      cout << it.first << ' ' << it.second << '\n';
//    }
//  }
  cin >> q;
  while (q--) {
    int r, w;
    cin >> r >> w; r--;
    r = d.root(r);
//    deb(r);
    int res = 0;
    for (auto &x : mp[r]) {
      int a, b;
      tie(a, b) = x;
//      deb(a);
//      deb(b);
      if (a and w % a == 0) {
        res += (w / a) * b;
      }
    }
    cout << w - res << '\n';
  }
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


