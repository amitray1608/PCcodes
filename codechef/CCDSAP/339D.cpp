//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = pow(2, 17)+1;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
int tree[siz*4];
void build(int n, int s, int e, int a[], int status) {
  if(s > e)
      return;
  if(s == e) {
    tree[n] = a[s];
    return;
  }
  int mid = (s+e) >> 1;
  build(n+n, s, mid, a, status^1);
  build(n+n+1, mid+1, e, a, status^1);
  if(status)
    tree[n] = tree[n+n] | tree[n+n+1];
  else
    tree[n] = tree[n+n] ^ tree[n+n+1];
}

void update(int n, int s, int e, int pos, int val, int status){
  if(s == pos and e == pos){
    tree[n] = val;
    return;
  }
  int mid = (s+e) >> 1;
  if(pos <= mid)
    update(n+n, s, mid, pos, val, status^1);
  else
    update(n+n+1, mid+1, e, pos, val, status^1);
  if(status)
    tree[n] = tree[n+n] | tree[n+n+1];
  else
    tree[n] = tree[n+n] ^ tree[n+n+1];
}

void solve(){
  int x, q;
  cin >> x >> q;
  int n = (1 << x);
  // cout << n << endl;
  int a[n];
  for(int &i : a) cin >> i;
  build(1, 0, n-1, a, x&1);
  while(q--){
    int l, r;
    cin >> l >> r;
    l--;
    update(1, 0, n-1, l, r, x&1);
    cout << tree[1] << endl;
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
