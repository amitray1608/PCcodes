
#include<bits/stdc++.h>

using namespace std;

vector<int> tree;

int query(int n, int s, int e, int x) {
  if (e - s == 1) 
    return s;
  int mid = (s + e) >> 1;
  if (tree[n + n] < x) {
    return query(n + n, s, mid, x);
  } else {
    return query(n + n + 1, mid, e, x);
  }
}

void update(int n, int s, int e, int p, int v) {
  if (e - s == 1) {
    tree[n] = v;
    return;
  }
  int mid = (s + e) >> 1;
  if (p < mid) {
    update(n + n, s, mid, p, v);
  } else {
    update(n + n + 1, mid + 1, e, p, v);
  }
  tree[n] = min(tree[n + n], tree[n + n + 1]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  tree.resize(n * 4, -1);
  vector<int> a(n);
  for (int &i : a) cin >> i;
  int mini = 1e9;
  for (int i = 0; i < n; i++) {
    update(1, 0, n - 1, i, a[i]);
    if (i < m - 1) continue;
    mini = min(mini, query(1, 0, n - 1, i - m + 1));
  }
  cout << mini << '\n';
  return 0;
} //Hajimemashite

