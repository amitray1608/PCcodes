
#include<bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 3;
int a[maxn];
int tree[maxn * 4];

void update(int n, int s, int e, int p, int v) {
  if (s > e) return;
  if (s == e and p == e) {
    tree[n] = v;
    return;
  }
  int mid = (s + e) / 2;
  if (p <= mid)
    update(n + n, s, mid, p, v);
  else
    update(n + n + 1, mid + 1, e, p, v);
  tree[n] = min(tree[n + n], tree[n + n + 1]);
}

int query(int n, int s, int e, int l, int r) {
  if (s > e or s > r or e < l) return INT_MAX;
  if (l <= s and e <= r) return tree[n];
  int mid = (s + e) / 2;
  return min(query(n + n, s, mid, l, r), query(n + n + 1, mid + 1, e, l, r));
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    update(1, 0, n - 1, i, x);
  }
  while (q--) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    cout << query(1, 0, n - 1, u, v) << '\n';
  }
  return 0;
} //Hajimemashite

