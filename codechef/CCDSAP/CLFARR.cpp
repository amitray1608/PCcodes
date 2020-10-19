//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

vector<int>tree, lazy;

void push(int n) {
  tree[n+n] = lazy[n];
  lazy[n+n] = lazy[n];
  tree[n+n+1] = lazy[n];
  lazy[n+n+1] = lazy[n];
  lazy[n] = 0;
}

void update(int n, int s, int e, int l, int r, int v) {
  if(l > r)
    return;
  if(s >= l and e <= r) {
    lazy[n] = v;
    tree[n] = v;
    return;
  } else {
    push(n);
    int mid = (s+e) >> 1;
    update(n+n, s, mid, l, min(r, mid), v);
    update(n+n+1, mid+1, e, max(l, mid+1), r, v);
    tree[n] = v;
  }
}

int query(int n, int s, int e, int l, int r) {
  if(l > r)
    return -1;
  if(s >= l and e <= r)
    return tree[n];
  push(n);
  int mid = (s+e) >> 1;
  if(l <= mid)
    return query(n+n, s, mid, l, r);
  else
    return query(n+n+1, mid+1, e, l, r);
}

void solve(){
  int n, q;
  cin >> n >> q;
  tree.resize(n*4, 0);
  lazy.resize(n*4, -1);
  while(q--) {
    int l, r, x;
    cin >> l >> r >> x;
    l--, r--;
    update(1, 0, n-1, l, r, x);
  }
  for(int i = 0; i < 15; i++) {
    cout << tree[i] <<' ';
  } cout << endl;  
  for(int i = 0; i < 15; i++) {
    cout << lazy[i] <<' ';
  } cout << endl;
  for(int i = 0; i < n; i++) {
    cout << query(1, 0, n-1, i, i) << endl;
  }

}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while(t--){
    //tt++;
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  