//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

ll tree[4*100000+1], lazy[4*100000+1];

void push(ll n, ll l, ll r){
  // deb(lazy[n]);
  if(lazy[n] == 0)
      return;
  tree[n] += (r-l+1)*lazy[n];
  // deb(tree[n]);
  if(l != r){
    lazy[n << 1] += lazy[n];
    lazy[(n << 1)|1] += lazy[n];
  }
  lazy[n] = 0;
}

void update(ll node, ll s, ll e, ll l, ll r, ll val){
  push(node, s, e);
  if(s > r or e < l)
      return;
  if(s >= l and e <= r){
    lazy[node] += val;
    push(node, s, e);
    // cout << "At " << node << " val = " << val << endl;
    return;
  }
  ll mid = (s+e) >> 1;
  update(node << 1, s, mid, l, r, val);
  update((node << 1) | 1, mid+1, e, l, r, val);
  tree[node] = tree[node << 1] + tree[(node << 1)| 1];
}

ll query(ll node, ll s, ll e, ll l, ll r){
  push(node, s, e);
  if(s > r or e < l)
      return 0;
  if(s >= l and  e <= r)
      return tree[node];
  ll mid = (s+e) >> 1;
  return (query(node << 1, s, mid, l, r) + query((node << 1) | 1, mid+1, e, l, r));
}

void solve(){
  ll n, c;
  cin >> n >> c;
  memset(tree, 0, sizeof tree);
  memset(lazy, 0, sizeof lazy);
  while(c--){
    ll x, l, r;
    cin >> x >> l >> r;
    // cout << x << ' ' << l << ' ' << r << ' ';
    l--, r--;
    if(x){
      ll ans = query(1, 0, n-1, l, r);
      cout << ans << endl;
    }else{
      ll val;
      cin >> val;
      // cout << val << endl;
      update(1, 0, n-1, l, r, val);
      // cout << "ok" << endl;
    }
  }
  // for(int i = 1; i < 15; i++)
  //     cout << tree[i] << ' ';
  // cout << endl;
  // for(int i = 1; i < 15; i++)
  //     cout << lazy[i] << ' ';
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll t = 1;
  cin >> t;
  while(t--){
    //tt++;
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  