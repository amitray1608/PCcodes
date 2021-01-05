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
  vector<ll> tree;
  
  SegTree(int n) {
    N = n;
    tree.resize(n * 4 + 1, 0);
  }

  void update(int n, int s, int e, int p, int v) {
    if(s > e) return;
    if(s == e) {
      tree[n] += v;
      return;
    }
    int mid = s + e >> 1;
    if(p <= mid) update(n + n, s, mid, p, v);
    else update(n + n + 1, mid + 1, e, p, v);
    tree[n] = (tree[n + n] + tree[n + n + 1]);
  }

  ll query(int n, int s, int e, int l, int r) {
    if(s > e or s > r or e < l) return 0;
    if(l <= s and e <= r) return tree[n];
    int mid = s + e >> 1;
    return query(n + n, s, mid, l, r) + query(n + n + 1, mid + 1, e, l, r);
  }
  
  void update(int p, int v) {
    update(1, 0, N - 1, p, v);
  }

  ll query(int v) {
    return query(1, 0, N - 1, 0, v);
  }

};


void solve() {
  int n, q;
  cin >> n >> q;
  SegTree st(n);
  
  while(q--) {
    int tp;
    cin >> tp;
    if(tp == 1) {
      int l, r, v;
      cin >> l >> r >> v;
      st.update(l, v);
      if(r == n) continue;
      st.update(r, -v);
    } else {
      int v;
      cin >> v;
      cout << st.query(v) << '\n';
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1, tt = 0;
  //cin >> t;
  while(t--){
    //cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite
