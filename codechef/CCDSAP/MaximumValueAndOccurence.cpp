//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
const int INF = 1e9;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

pair<int, int>tree[siz*4];

pair<int, int> combine(pair<int, int>a, pair<int, int>b) {
  if(a.first > b.first)
      return a;
  if(a.first < b.first)
      return b;
  return make_pair(a.first, a.second+b.second);
}

void build(int n, int s, int e, int a[]) {
  if(s > e)
      return;
  if(s == e) {
    tree[n] = {a[s], 1};
    return;
  }
  int mid = (s+e) >> 1;
  build(n+n, s, mid, a);
  build(n+n+1, mid+1, e, a);
  tree[n] = combine(tree[n+n], tree[n+n+1]);
}

void update(int n, int s, int e, int pos, int val) {
  if(s > e)
      return;
  if(s == pos and e == pos) {
    tree[n] = {val, 1};
    return;
  }
  int mid = (s+e) >> 1;
  if(mid >= pos)
    update(n+n, s, mid, pos, val);
  else
      update(n+n+1, mid+1, e, pos, val);
  tree[n] = combine(tree[n+n], tree[n+n+1]);
}

pair<int, int> query(int n, int s, int e, int l, int r) {
  if(s > e) 
    return make_pair(-INF, 0);
  if(s > r or e < l)
      return make_pair(-INF, 0);
  if(s >= l and e <= r)
      return tree[n];
  int mid = (s+e) >> 1;
  return combine(query(n+n, s, mid, l, r), query(n+n+1, mid+1, e, l, r));
}

void solve() {
  int n;
  cin >> n;
  int a[n];
  for(int &i : a) cin >> i;
  build(1, 0, n-1, a);
  // cout << "ok" << endl; 
  int q;
  cin >> q;
  while(q--) {
    char c;
    cin >> c;
    if(c == 'q') {
      int l, r;
      cin >> l >> r;
      l--, r--;
      pair<int, int> ans = query(1, 0, n-1, l, r);
      cout << ans.first << ' ' <<  ans.second << endl;
    } else {
      int pos, val;
      cin >> pos >> val;
      pos--;
      update(1, 0, n-1, pos, val);
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while(t--){
    //tt++;
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  

/*
1
8
6 8 7 8 6 7 6 7
4
q 2 4
u 5 7
q 1 7
q 5 8
*/