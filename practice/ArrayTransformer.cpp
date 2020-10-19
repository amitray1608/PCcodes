#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef double dd;
const int MOD = 1e9 + 7;

void solve() {
  ll n, m, u;
  cin >> n >> m >> u;
  vector<ll>a(n);
  for(ll &i : a) cin >> i;
  ll B = (ceil(sqrt(n+0.0)));
  vector<ll>b[B];
  for(ll i = 0; i < n; i++) {
    b[i/B].push_back(a[i]);
  }
  for(ll i = 0; i < ceil(n/B); i++)
    sort(b[i].begin(), b[i].end());

  while(m--) {
    ll l, r, v, p;
    cin >> l >> r >> v >> p;
    l--, r--, p--;
    ll k = 0, L = 0, R = 0, i = 0;
    //Count elements strictly less than v.
    ll lblock = l/B, rblock = r/B;
    if(lblock == rblock) {
        for(int i = l; i <= r; i++) 
            if(a[i] < v)
              k++;
    } else {
      if(l%B)
      lblock++;
      for(i = l; i < lblock*B; i++) 
        if(a[i] < v) k++;
      while(i + B - 1  <= r) {
        ll bb = i/B;
        k += upper_bound(b[bb].begin(), b[bb].end(), v-1) - b[bb].begin();
        i += B;
      }
      while(i <= r) {
        if(a[i] < v)
          k++;
        i++;
      }
    }
    //deb(k);
    //update the array.
    //new val.
    ll nval = (u*k)/(r-l+1);
    //deb(nval);
    //deb(r);
    //deb(l);
    ll pos = p/B;
    ll curr = a[p];
    ll lo = 0, hi = B - 1;
    while(lo <= hi) {
      ll mid = lo + (hi-lo)/2;
      if(b[pos][mid] == curr) {
        b[pos][mid] = nval;
        break;
      } else if(b[pos][mid] < curr)
        lo = mid + 1;
      else
        hi = mid - 1;
    }
    a[p] = nval;
    sort(b[pos].begin(), b[pos].end());
  }
  for(ll i : a) cout << i << endl;
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  //#ifndef ONLINE_JUDGE
 // freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  //#endif
  ll t = 1, tt = 0;
  //cin >> t;
  while(t--){
    //tt++;
    //cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}

