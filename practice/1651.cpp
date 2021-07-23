
#include<bits/stdc++.h>

using namespace std;
#define int int64_t

const int maxn = 2e5 + 3;
int tree[maxn * 4];
int lazy[maxn * 4];

void up(int n) {
  tree[n + n] += lazy[n];
  lazy[n + n] += lazy[n];
  tree[n + n + 1] += lazy[n];
  lazy[n + n + 1] += lazy[n];
  lazy[n] = 0;
}

void update(int n, int s, int e, int l, int r, int v) {
  if (s > e or s > r or e < l) return;
  if (l <= s and e <= r) {
    tree[n] += v;
    lazy[n] += v;
    return;
  }
  up(n);
  int mid = (s + e) / 2;
  update(n + n, s, mid, l, r, v);
  update(n + n + 1, mid + 1, e, l, r, v);
  tree[n] = tree[n + n] + tree[n + n + 1];
}

int query(int n, int s, int e, int p) {
  if (s > e) return 0;
  if (s == e and e == p) return tree[n];
  int mid = (s + e) / 2;
  up(n);
  if (p <= mid) return query(n + n, s, mid, p);
  return query(n + n + 1, mid + 1, e, p);
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int n, q;
  cin >> n >> q;
  memset(lazy, 0, sizeof lazy);
  memset(tree, 0, sizeof tree);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    update(1, 0, n - 1, i, i, x);
  }
  while (q--) {
    int tp;
    cin >> tp;
    if (tp == 1) {
      int u, v, c;
      cin >> u >> v >> c;
      u--, v--;
      update(1, 0, n - 1, u, v, c);
    } else {
      int k;
      cin >> k;
      k--;
      cout << query(1, 0, n - 1, k) << '\n';
    }
  }
  return 0;
} //Hajimemashite

