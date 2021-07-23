#include<bits/stdc++.h>
 
using namespace std;
#define int int64_t
 
const int maxn = 2e5 + 3;
int pos[maxn * 4];
int tree[maxn * 4];
 
void update(int n, int s, int e, int p, int v) {
  if (s > e) return;
  if (s == e and p == e) {
    tree[n] += v;
    pos[n] = s;
    return;
  }
  int mid = (s + e) / 2;
  if (p <= mid)
    update(n + n, s, mid, p, v);
  else
    update(n + n + 1, mid + 1, e, p, v);
  tree[n] = (tree[n + n] + tree[n + n + 1]);
}
 
int query(int n, int s, int e, int v) {
  if (s > e) return 0;
  if (tree[n] == v and s == e) return pos[n];
  int mid = (s + e) / 2;
  if (tree[n + n] >= v) 
    return query(n + n, s, mid, v);
  return query(n + n + 1, mid + 1, e, v);
}
 
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  memset(tree, 0, sizeof tree);
  int n;
  cin >> n;
  vector<int> c(n);
  memset(tree, 0, sizeof tree);
  memset(pos, 0, sizeof pos);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    c[i] = x;
    update(1, 0, n - 1, i, 1);
  }
  for (int i = 0; i < n; i++) {  
    int x;
    cin >> x;
    int res = query(1, 0, n - 1, x);
//    cout << res << '\n';
    cout << c[res] << ' ';
    update(1, 0, n - 1, res, -1);
  }
  return 0;
} //Hajimemashite
