
#include <bits/stdc++.h>

using namespace std;

class segTree {
  public:
  vector<pair<int, int>> tree;
  int N;

  segTree(int n) : N(n) {
    tree.resize(4 * N + 1);
    for (int i = 0; i < 4 * N + 1; i++) {
      tree[i].first = 0, tree[i].second = INT_MAX;
    }
  }

  void update(int n, int s, int e, int p, int v) {
    if (s > e) {
      return;
    }
    if (s == e and e == p) {
      tree[n].first = tree[n].second = v;
      return;
    }

    int mid = (s + e) >> 1;
    if (p <= mid)
      update(n + n, s, mid, p, v);
    else
      update(n + n + 1, mid + 1, e, p, v);
    tree[n].first = max(tree[n + n].first, tree[n + n + 1].first);
    tree[n].second = min(tree[n + n].second, tree[n + n + 1].second);
  }

  array<int, 2> query(int n, int s, int e, int l, int r) {
    if (s > e or s > r or e < l) {
      return array<int, 2> ({INT_MAX, INT_MIN});
    }
    if (l <= s and e <= r) {
      array<int, 2> ({tree[n].first - tree[n].second});
    }
    int mid = (s + e) >> 1;
    if (r <= mid)
      return query(n + n, s, mid, l, r);
    else if (l > mid)
      return query(n + n + 1, mid + 1, e, l, r);
    else {
      array<int, 2> res, ress;
      res = query(n + n + 1, mid + 1, e, l, r);
      ress = query(n + n, s, mid, l, r);
      return array<int, 2>({max(res[0], ress[0]), min(res[1], ress[1])});
    }
  }
};

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  segTree st(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    st.update(1, 0, n - 1, i, a[i]);
  }
  int l = 0, r = 1;
  int maxi = 1;
  for (int i = 1; i < n; i++) {
    while (l < i) {
      array<int, 2> res = st.query(1, 0, n - 1, l, i);
      if (res[0] - res[1] <= 1) {
        break; 
      } else l++;
    }
    maxi = max(maxi, i - l + 1);
  }
  cout << maxi << '\n';
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


