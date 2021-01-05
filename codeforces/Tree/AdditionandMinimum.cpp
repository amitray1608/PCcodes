#include<bits/stdc++.h>

#define int int64_t
using namespace std;

const int inf = 1e18;
const int maxn = 1e5 + 1;
int tree[maxn * 4], lazy[maxn * 4];
int a[maxn];

void build(int n, int s, int e) {
  if(s > e) return;
  if(s == e) {
    tree[n] = a[s];
    return;
  }
  int mid = (s + e) >> 1; 
  build(n + n, s, mid);
  build(n + n + 1, mid + 1, e);
  tree[n] = min(tree[n + n], tree[n + n + 1]);
  return;
}

void push(int n) {
  if(lazy[n] != 0) {
    tree[n + n] += lazy[n];
    lazy[n + n] += lazy[n];
    tree[n + n + 1] += lazy[n];
    lazy[n + n + 1] += lazy[n];
    lazy[n] = 0;
  }
}

void update(int n, int s, int e, int l, int r, int v) {
  if(s > e or s > r or e < l) return;
  if(l <= s and e <= r) {
    tree[n] += v;
    lazy[n] += v;
    return;
  }
  push(n);
  int mid = (s + e) >> 1;
  update(n + n, s, mid, l, r, v);
  update(n + n + 1, mid + 1, e, l, r, v);
  tree[n] = min(tree[n + n], tree[n + n + 1]);
  return;
}

int query(int n, int s, int e, int l, int r) {
  if(s > r or e < l) return inf;
  if(l <= s and e <= r) return tree[n];
  push(n);
  int mid = (s + e) >> 1;
  return min(query(n + n, s, mid, l, r), query(n + n + 1, mid + 1, e, l, r)); 
}

void solve() {
  int n, q;
  cin >> n >> q;
  for(int i = 0; i < n * 4 + 1; i++) tree[i] = 0;
  memset(lazy, 0, sizeof lazy);
  while(q--) {
    int tp, l, r, x;
    cin >> tp >> l >> r;
    if(tp == 1) {
      cin >> x;
      update(1, 0, n - 1, l, r - 1, x);
    } else {
      cout << query(1, 0, n - 1, l, r - 1) << '\n';
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
//  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
