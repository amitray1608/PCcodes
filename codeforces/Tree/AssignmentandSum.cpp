#include<bits/stdc++.h>

using namespace std;
#define int int64_t

class Segtree {
 public:
  int N;
  vector<int> tree, lazy;
 
  Segtree(int n) : N(n) {
    tree.resize(n * 4 + 1, 0);
    lazy.resize(n * 4 + 1, 0);
  }
 
  void push(int n, int s, int e, int mid) {
    if(lazy[n] == 0) return;
    tree[n + n] = (mid - s + 1) * lazy[n];
    lazy[n + n] = lazy[n];
    lazy[n + n + 1] = lazy[n];
    tree[n + n + 1] = (e - mid) * lazy[n];
    lazy[n] = 0;
  }
 
  void update(int n, int s, int e, int l, int r, int v) {
    if(s > e or s > r or e < l) return;
    if(l <= s and e <= r) {
      tree[n] = (e - s + 1) * v;
      lazy[n] = v;
      return;
    }
    int mid = s + e >> 1;
    push(n, s, e, mid);
    update(n + n, s, mid, l, r, v);
    update(n + n + 1, mid + 1, e, l, r, v);
    tree[n] = tree[n + n] + tree[n + n + 1];
  }
  
  int query(int n, int s, int e, int l, int r) {
    if(s > e or s > r or e < l) return 0;
    if(l <= s and e <= r) return tree[n];
    int mid = s + e >> 1;
    push(n, s, e, mid);
    return query(n + n, s, mid, l, r) + query(n + n + 1, mid + 1, e, l, r);
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
