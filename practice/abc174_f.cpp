//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

const int N = 2e5+1;
int c[N];
int p[N];
int f[N];
int ans[N];
int lz[N];
vector<pair<int,int>> qr[N];

void push(int n) {
  lz[n+n] += lz[n];
  lz[n+n+1] += lz[n];
  lz[n] = 0;
}

void upd(int n, int s, int e, int l, int r, int v) {
  if(s > r or e < l) return;
  if(l <= s and e <= r) {
    lz[n] += v;
    return;
  }
  push(n);
  int mid = (s+e) >> 1;
  upd(n+n, s, mid, l, r, v);
  upd(n+n+1, mid+1, e, l, r, v);
}

int query(int n, int l, int r, int pp) {
  if(l == r) return lz[n];
  push(n);
  int mid = (l+r) >> 1;
  if(pp <= mid) 
    return query(n+n, l, mid, pp);
  else
    return query(n+n+1, mid+1, r, pp);
}

void solve() {
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> c[i];
    p[i] = f[c[i]];
    f[c[i]] = i;
  }
  int q;
  cin >> q;
  for(int i = 1; i <= q; i++) {
    int l, r;
    cin >> l >> r;
    qr[r].push_back({l, i});
  }
  for(int i = 1; i <= n; i++) {
    upd(1, 1, n, p[i]+1, i, 1);
    for(auto cc : qr[i]) {
      ans[cc.second] = query(1, 1, n, cc.first);
    }
  }
  for(int i = 1; i <= q; i++)
    cout << ans[i] << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(10);
  int t = 1;
  // cin >> t;
  for(int tt = 1; tt <= t; tt++) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  