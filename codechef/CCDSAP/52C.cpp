#include <bits/stdc++.h>

using namespace std;
using LL = long long;

template<typename T>
class Tree {
  const T ID = 1.01e18;
  const T LID = 0;

  int n;
  vector<T> tree;
  vector<T> lazy;

public:
  Tree(int _n) : n(_n) {
    tree.resize((n + 1) * 4, LID);
    lazy.resize((n + 1) * 4, LID);
  }

  // f(ID, val) = val
  T f(T a, T b) {
    return min(a, b);
  }

  // Changes WRT questions
  void push(int x, int l, int r) {
    if(lazy[x] == LID) return;
    tree[x] += lazy[x];
    if(l != r) {
      lazy[x + x] += lazy[x];
      lazy[x + x + 1] += lazy[x];
    }
    lazy[x] = LID;
  }

  void upd(int l, int r, int ll, int rr, int x, T val) {
    push(x, l, r);
    if(r < ll || rr < l) return;
    if(ll <= l && rr >= r) {
      lazy[x] += val;
      push(x, l, r);
      return;
    }
    int m = (l + r) >> 1;
    upd(l, m, ll, rr, x + x, val);
    upd(m + 1, r, ll, rr, x + x + 1, val);
    tree[x] = f(tree[x + x], tree[x + x + 1]);
  }

  T qry(int l, int r, int ll, int rr, int x) {
    push(x, l, r);
    if(r < ll || rr < l) return ID;
    if(ll <= l && rr >= r) return tree[x];
    int m = (l + r) >> 1;
    return f(qry(l, m, ll, rr, x + x), 
        qry(m + 1, r, ll, rr, x + x + 1));
  }

  void update(int l, int r, T val) {
    upd(0, n - 1, l, r, 1, val); 
  }

  T query(int l, int r) {
    return qry(0, n - 1, l, r, 1);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n; cin >> n;
  Tree<LL> T(n);
  for(int i = 0; i < n; ++i) {
    LL x; cin >> x;
    T.update(i, i, x);
  }
  int q; cin >> q;
  string buff;
  cin.ignore();
  while(q--) {
    int l, r, v;
    getline(cin, buff);
    stringstream ss;
    ss << buff;
    ss >> l >> r;
    if(ss >> v) {
      if(l > r) {
        T.update(0, r, v);
        T.update(l, n - 1, v);
      } else {
        T.update(l, r, v);
      }
    } else {
      LL ans = 0;
      if(l > r) ans = min(T.query(0, r), T.query(l, n - 1));
      else ans = T.query(l, r);
      cout << ans << '\n';
    }
  }
  return 0;
}
