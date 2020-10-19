//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

const int INF = 1e9;
pair<int, int> t[4*MAXN];
int n, q;
pair<int, int> combine(pair<int, int> a, pair<int, int> b) {
  if (a.first > b.first) 
      return a;
  return b;
}

void build(vector<int> a, int v, int tl, int tr) {
    if (tl == tr) {
      if(tl >= 0 and tl <= n-1)
        t[v] = make_pair(a[tl], tl);
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

pair<int, int> query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return make_pair(-INF, 0);
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    return combine(query(v*2, tl, tm, l, min(r, tm)), query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = make_pair(tl, tl);
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

void solve() {
  // int n, q;
  cin >> n >> q;
  vector<int> a, b;
  for(int &i : a) cin >> i;
  for(int &i : b) cin >> i;
  build(a, 1, 0, n-1);
  while(q--) {
    int tp;
    cin >> tp;
    if(tp == 1) {
      int x, y, qt;
      cin >> x >> y >> qt;
      x--, y--;
      auto c = query(1, 0, n-1, x, y);
      int pos = c.second;
      b[pos] += qt;
    } else {
      int v, i, qt, thr;
      cin >> v >> i >> qt >> thr;
      i--;
      int l = max(0, i-v);
      int r = min(n-1, i+v);
      auto c = query(1, 0, n-1, l, r);
      if(thr < b[c.second] or qt < thr) {
        cout << c.second+1 << endl;
        b[c.second] -= qt;
      } else {
        cout << "No Purchase" << endl;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(10);
  int it = 1;
  cin >> it;
  for(int tt = 1; tt <= it; tt++) {
    //cout << "Case #" << tt << ": ";
    solve();
 }
  return 0;
}  
