#include<bits/stdc++.h>

using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;

class SegTree { 
  public:
  struct Node {
    ll prefix = 0, suffix = 0, maxi = 0, total = 0;

    void init(int n) {
      prefix = suffix = maxi = total = n;
    }

    void merge (Node a, Node b) {
      this->prefix = max(a.prefix, a.total + b.prefix);
      this->suffix = max(b.suffix, b.total + a.suffix);
      this->total = b.total + a.total;
      this->maxi = max(a.maxi, max(b.maxi, a.suffix + b.prefix));
    }
  };

  int N;
  vector<Node> tree;
  SegTree(int n) {
    N = n;
    tree.resize(N * 4 + 1);
  }
  
  void update(int n, int s, int e, int p, int v) {
    if(s > e) return;
    if(s == e) {
      tree[n].init(v);
      return;
    }
    int mid = s + e >> 1;
    if(p <= mid) update(n + n, s, mid, p, v);
    else update(n + n + 1, mid + 1, e, p, v);
    tree[n].merge(tree[n + n], tree[n + n + 1]);
  }
  
  void update(int p, int v) {
    update(1, 0, N - 1, p, v);
  }

  ll query() {
    return tree[1].maxi;
  }

};


void solve() {
  int n, q; cin >> n >> q;
  SegTree st(n);
  int a[n];
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    st.update(i, a[i]);
  }
  ll ans = st.query();
  cout << (ans < 0 ? 0 : ans) << endl;
  while(q--) {
    int r, v; cin >> r >> v;
    st.update(r, v);
    ans = st.query();
    cout << (ans < 0 ? 0 : ans) << endl;
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
