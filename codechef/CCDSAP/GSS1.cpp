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
  ll pre, suf, maxi, total;
  void fill(ll n) {
    pre = suf = maxi = total = n;
  }
  void merge(Node a, Node b) {
    this->pre = max(a.total+b.pre, a.pre);
    this->suf = max(b.total+a.suf, b.suf);
    this->total = a.total + b.total;
    this->maxi = max({b.pre + a.suf, a.maxi, b.maxi});
  }  
 }tree[siz*4];

void update(ll n, ll s, ll e, ll p, ll val) {
  if(s > e)
      return;
  if(s == p and e == p) {
    tree[n].fill(val);
    return;
  }
  ll mid = (s+e) >> 1;
  if(p <= mid)
      update(n+n, s, mid, p, val);
  else
    update(n+n+1, mid+1, e, p, val);
  tree[n].merge(tree[n+n], tree[n+n+1]);
}

Node query(ll n, ll s, ll e, ll l, ll r) {
  // if(s > e)
  //     return -MOD;
  if(s >= l and e <= r)
      return tree[n];
  ll mid = (s+e) >> 1;
  if(r <= mid)
   return query(n+n, s, mid, l, r);
  else if(l > mid)
    return query(n+n+1, mid+1, e, l, r);
  else{
    Node ans;
    ans.merge(query(n+n, s, mid, l, r), query(n+n+1, mid+1, e, l, r));
    return ans;
  }
}

 void solve(){
   ll n;
   cin >> n;
   for(ll i = 0; i < n; i++) {
    ll x;
    cin >> x;
    update(1, 0, n-1, i, x);
   }
   // for(ll i = 1; i < 13; i++){
   //  cout << tree[i].maxi << ' '; 
   // }cout << endl;

   ll q;
   cin >> q;
   while(q--){
    // ll tp;
    // cin >> tp;
    // if(tp) {
      ll l, r;
      cin >> l >> r;
      l--, r--;
      cout << query(1, 0, n-1, l, r).maxi << endl;
    // } else {
    //   ll p, v;
    //   cin >> p >> v;
    //   p--;
    //   update(1, 0, n-1, p, v);
      // for(ll i = 1; i < 13; i++){
      // cout << tree[i].maxi << ' '; 
      // }cout << endl;
    // }
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