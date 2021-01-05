#include<bits/stdc++.h>

using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;

class SegTree {
  public:
    int N, inf;
    vector<array<int, 2>> tree;
 
    SegTree(int n, int a[]) {
      N = n;
      inf = INT_MAX;
      tree.resize(n * 4 + 1);
      for(int i = 0; i < n * 4 + 1; i++) tree[i][0] = inf;
      build(1, 0, n - 1, a);
    }
 
    void merge(int n) {
      if(tree[n + n][0] == tree[n + n + 1][0]){ 
        tree[n][0] = tree[n + n][0];
        tree[n][1] = tree[n + n][1] + tree[n + n + 1][1];
      } 
      else if(tree[n + n][0] < tree[n + n + 1][0]) {
        tree[n][0] = tree[n + n][0];
        tree[n][1] = tree[n + n][1];
      } 
      else {
        tree[n][0] = tree[n + n + 1][0];
        tree[n][1] = tree[n + n + 1][1];
      }
    }
 
    void build(int n, int s, int e, int a[]) {
      if( s > e ) return;
      if(s == e) {
        tree[n][0] = a[s];
        tree[n][1] = 1;
        return;
      }
      int mid = (s + e) / 2;
      build(n + n, s, mid, a);
      build(n + n + 1, mid + 1, e, a);
      merge(n);
    }
 
    void update(int n, int s, int e, int p, int v) {
      if(s > e) return;
      if(s == e) {
        tree[n][0] = v;
        tree[n][1] = 1;
        return;
      }
      int mid = (s + e) / 2;
      if(p <= mid) update(n + n, s, mid, p, v);
      else update(n + n + 1, mid + 1, e, p, v);
      merge(n);
    }
 
    array<int, 2> query(int n, int s, int e, int l, int r) {
      array<int, 2> x = {inf, 0};
      if(s > e || s > r || e < l) return x;
      if(l <= s && e <= r) return tree[n];
      int mid = (s + e) / 2;
      array<int, 2> a = query(n + n, s, mid, l, r);
      array<int, 2> b = query(n + n + 1, mid + 1, e, l, r);
      if(a[0] == b[0]) {
        a[1] += b[1];
        return a;
      } else if(a[0] < b[0]) return a;
      else return b;
    }
 
    void update(int p, int v) {
      update(1, 0, N - 1, p, v);
    }
 
    array<int, 2> query(int l, int r) {
      return query(1, 0, N - 1, l, r);
    }
 
  };

void solve() {
  int n, q;
  cin >> n >> q;
  int a[n];
  for(int i = 0; i < n; i++) cin >> a[i];
  SegTree st(n, a);
  
  while(q > 0) {
    q--;
    int tp, l, r;
    cin >> tp >> l >> r;
    if(tp == 1) {
      st.update(l, r);
    } else {
      array<int, 2> ans = st.query(l, r - 1);
      cout << ans[0] << ' ' << ans[1] << endl;
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
