//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e5 + 1;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
vector<ll> a, tree, lazy;
const ll maxi = 1e18;
void propogate(int node, int l, int r){
  if(lazy[node] == 0) 
      return;
  tree[node] += lazy[node];
  if( l != r ) {
    lazy[node << 1] += lazy[node];
    lazy[(node << 1) | 1] += lazy[node];
  }
  lazy[node] = 0;
}

void update(int node, int s, int e, int l, int r, ll val){
  propogate(node, s, e);
  if(s > r or e < l)
      return;
  if(s >= l and e <= r){
    lazy[node] += val;
    propogate(node, s, e);
    return;
  }
  int mid = (s+e) >> 1;
  update(node << 1, s, mid, l, r, val);
  update((node << 1) | 1, mid + 1, e, l, r, val);
  tree[node] = min(tree[node << 1], tree[(node << 1) | 1]);
}

ll query(int node, int s, int e, int l, int r){
  propogate(node, s, e);
  if(s > r or e < l)
    return maxi;
  if(s >= l and e <= r)
      return tree[node];
  int mid = (s+e) >> 1;
  return min(query(node << 1, s, mid, l, r), query((node << 1) | 1, mid+1, e, l, r));
}

void solve(){
  int n;
  cin >> n;
  a.resize(n, 0);
  tree.resize(4*(n+1), 0);
  lazy.resize(4*(n+1), 0);
  for(int i = 0; i < n; i++) cin >> a[i], update(1, 0, n-1, i, i, a[i]);
  int q;
  cin >> q;
  string s;
  cin.ignore();
  while(q--){
    getline(cin, s);
    stringstream ss;
    ss << s;
    int l, r, v;
    ss >> l >> r;
    // cout << "D" << endl;
    // cout << l << ' ' << r << ' ';
    if(ss >> v){
      // cout << v;
        if(l > r){
          update(1, 0, n-1, 0, r, v);
          update(1, 0, n-1, l, n-1, v);
        }else
          update(1, 0, n-1, l, r, v);
    }else{
        ll ans;
        if(l > r)
          ans = min(query(1, 0, n-1, l, n-1), query(1, 0, n-1, 0, r));
        else
          ans = query(1, 0, n-1, l, r);
        cout << ans << endl;
    }
    // cout << endl;
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