#include<bits/stdc++.h>

using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;

class SegTree {
 public:
   int N;
   vector<array<int, 2>> tree;

  SegTree(int n) {
     N = n;
     tree.resize(n * 4 + 1);
   }

   void update(int n, int s, int e, int p, int pos, int v) {
     if(s > e) return;
     if(s == e) {
      tree[n][0] = v;
      tree[n][1] = pos;
      return;
     }
     int mid = s + e >> 1;
     if(p <= mid) {
      update(n + n, s, mid, p, pos, v);
     } else {
       update(n + n + 1, mid + 1, e, p, pos, v);
     }
     tree[n] = min(tree[n + n], tree[n + n + 1]);
   }

   array<int, 2> query(int n, int s, int e, int l, int r) {
     if(s > e or s > r or e < l) return {INT_MAX, -1};
     if(l <= s and e <= r) return tree[n];
     int mid = s + e >> 1;
     auto x = query(n + n, s, mid, l, r);
     auto y = query(n + n + 1, mid + 1, e, l, r);
     if(x[0] < y[0]) return x;
     else return y;
  }

  void update(int p, int pos, int v) {
    update(1, 0, N - 1, p, pos, v);
  }

  array<int, 2> query(int l, int r) {
    return query(1, 0, N - 1, l, r);
  }

};

void solve() {
  int n;
  cin >> n;
  vector<array<int, 3>> h(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> h[i][0] >> b[i][0];
    h[i][1] = b[i][0];
    b[i][1] = h[i][0];
    h[i][2] = i;
    b[i][2] = i;
  }

  sort(h.begin(), h.end());
  sort(b.begin(), b.end());

  SegTree ht(n);
  SegTree bt(n);
  for (int i = 0; i < n; i++) {
    ht.update(i, h[i][2], h[i][1]);
    bt.update(i, b[i][2], b[i][1]);
  }

  auto query = [&](int x, int y) {
    int p = lower_bound(h.begin(), h.end(), array<int, 3>{x, 0, 0}) - h.begin();
    auto q = ht.query(0, p - 1);
    if(q[0] < y) return q[1] + 1;
    p = lower_bound(b.begin(), b.end(), array<int, 3>{x, 0, 0}) - b.begin();
    q = bt.query(0, p - 1);
    if(q[0] < y) return q[1] + 1;
    return -1;
  };

  vector<int> res(n);
  for(int i = 0; i < n; i++) {
    int x = h[i][0], y = h[i][1], ind = h[i][2];
    res[ind] = query(x, y);
  }
  for (int i = 0; i < n; i++) {
    cout << res[i] << ' ';
  } 
  cout<< '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1, tt = 0;
  cin >> t;
  while(t--){
    //cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite
