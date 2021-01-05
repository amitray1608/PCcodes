#include<bits/stdc++.h>

#define int int64_t
using namespace std;

class Segtree {
  public:
  const int mod = 1e9 + 7;
  int N;
  vector<int> tree, lazy;
  
  Segtree(int _n) : N(_n) {
    tree.resize(N * 4 + 1, 0);
    lazy.resize(N * 4 + 1, 1);
  }
  
  void build(int n, int s, int e) {
    if(s > e) return;
    if(s == e) {
      tree[n] = 1;
      return;
    }
    int mid = (s + e) >> 1;
    build(n + n, s, mid);
    build(n + n + 1, mid + 1, e);
    tree[n] = (tree[n + n] + tree[n + n + 1]) % mod;
  }

  void push(int n) {
    tree[n + n] = (tree[n + n] * lazy[n]) % mod;
    lazy[n + n] = (lazy[n + n] * lazy[n]) % mod;
    tree[n + n + 1] = (tree[n + n + 1] * lazy[n]) % mod;
    lazy[n + n + 1] = (lazy[n + n + 1] * lazy[n]) % mod;
    lazy[n] = 1;
  }

  void update(int n, int s, int e, int l, int r, int v) {
    if(s > e or e < l or s > r) return;
    if(l <= s and e <= r) {
      tree[n] = (tree[n] *  v) % mod;
      lazy[n] = (lazy[n] * v) % mod;
      return;
    }
    push(n);
    int mid = (s + e) >> 1;
    update(n + n, s, mid, l, r, v);
    update(n + n + 1, mid + 1, e, l, r, v);
    tree[n] = (tree[n + n] + tree[n + n + 1]) % mod;
    return;
  }

  int query(int n, int s, int e, int l, int r) {
    if(s > e or s > r or e < l) return 0;
    if(l <= s and e <= r) {
      return tree[n];
    }
    push(n);
    int mid = (s + e) >> 1;
    return (query(n + n, s, mid, l, r) + query(n + n + 1, mid + 1, e, l, r)) % mod;
  }
  void update(int l, int r, int v) {
    update(1, 0, N - 1, l, r, v);
  }

  int query(int l, int r) {
    return query(1, 0, N - 1, l, r);
  }

};

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int n, q;
  cin >> n >> q;
  Segtree st(n);
  st.build(1, 0, n - 1);
  while(q--) {
    int tp, l, r, v;
    cin >> tp >> l >> r;
    if(tp == 1) {
      cin >> v;
      st.update(l, r - 1, v);
    } else {
      cout << st.query(l, r - 1) << '\n';
    }
  }
  return 0;
}
