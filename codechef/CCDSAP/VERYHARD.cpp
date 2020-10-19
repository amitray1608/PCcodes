//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

struct Node {
public:
  int rem[5];
  Node merge(Node a, Node b) {
    Node E;
    for(int i = 0; i < 5; i++) {
      E.rem[i] = a.rem[i] + b.rem[i]; 
    }
    return E;
  }
};

vector<Node>tree;
vector<int>a;
int N, k, q;

void build(int n, int s, int e) {
  if(s > e)
    return;
  if(s == e) {
    tree[n].rem[a[s]%k]++;
    return; 
  }
  int mid = (s+e) >> 1;
  build(n+n, s, mid);
  build(n+n+1, mid+1, e);
  tree[n] = tree[n].merge(tree[n+n], tree[n+n+1]);
}

void update(int n, int s, int e, int p, int pre) {
  if(s > e or s > p or e < p)
    return;
  if(s == e and e == p) {
    tree[n].rem[a[p]%k]++;
    tree[n].rem[pre%k]--;
    return;
  }
  int mid = (s+e) >> 1;
  if(p <= mid)
    update(n+n, s, mid, p, pre);
  else
    update(n+n+1, mid+1, e, p, pre);
  tree[n] = tree[n].merge(tree[n+n], tree[n+n+1]);
}

int query(int n, int s, int e, int l, int r, int x) {
  if(s > e or e < l or s > r)
    return 0;
  if(s >= l and e <= r)
    return tree[n].rem[x];
  int mid = (s+e) >> 1;
  return query(n+n, s, mid, l, r, x) + query(n+n+1, mid+1, e, l, r, x);
}

void solve() {
  cin >> N >> q >> k;
  tree.resize(N*5);
  a.resize(N, 0);
  for(int &i : a) cin >> i;
  build(1, 0, N-1);
  // for(int i = 1; i < 15; i++) {
  //   cout << "Node " << i << " : ";
  //   for(auto j : tree[i].rem)
  //     cout << j << ' ';
  //   cout << endl;
  // }
  while(q--) {
    int tp;
    cin >> tp;
    if(tp == 1) {
      int p, val;
      cin >> p >> val;
      a[p-1] += val;
      update(1, 0, N-1, p-1, a[p-1]-val);
    } else {
      int l, r, c;
      cin >> l >> r >> c;
      l--, r--;
      int ans = query(1, 0, N-1, l, r, c);
      cout << ans << endl;
    }
  }
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

/*
5 3 5
5 4 3 2 1
2 1 5 3
1 5 9
2 1 5 0
*/