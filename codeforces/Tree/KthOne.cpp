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
  vector<int> tree;

  SegTree(int n) : N(n) {
    tree.resize(n * 4 + 1);
  }

  void build(int n, int s, int e, vector<int> &a) {
    if(s > e) return;
    if(s == e) {
      tree[n] = a[s];
      return;
    }
    int mid = s + e >> 1;
    build(n + n, s, mid, a);
    build(n + n + 1, mid + 1, e, a);
    tree[n] = tree[n + n] + tree[n + n + 1];
  }

  void update(int n, int s, int e, int p) {
    if(s > e) return;
    if(s == e) {
      tree[n] ^= 1;
      return;
    }
    int mid = s + e >> 1;
    if(p <= mid) update(n + n, s, mid, p);
    else update(n + n + 1, mid + 1, e, p);
    tree[n] = tree[n + n] + tree[n + n + 1];
  }

  int query(int n, int s, int e, int k) {
    if(s > e) return s;
    if(s == e) {
      return s;
    }

    int mid = s + e >> 1;
    if(tree[n + n] > k) return query(n + n, s, mid, k);
    else return query(n + n + 1, mid + 1, e, k - tree[n + n]);
  }

  void update(int p) {
    update(1, 0, N - 1, p);
  }

  int query(int k) {
    return query(1, 0, N - 1, k); 
  }
};

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for(int &i : a) cin >> i;
  SegTree st(n);
  st.build(1, 0, n - 1, a);

  while(q--) {
    int tp, v;
    cin >> tp >> v;
    if(tp == 1) st.update(v);
    else cout << st.query(v)  << '\n';
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
