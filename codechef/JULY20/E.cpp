//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 998244353;
#define mod  %MOD
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void solve(){
  ll n, k;
  cin >> n >> k;
  vector<ll>a(n);
  for(ll &i : a) cin >> i;
  sort(a.begin(), a.end());
  ll count = 0;
  // count = (ll)(ceil(log2(ceil((double)(a[0])/(k*1.0)))))+1;
  ll i = 0;
  while(i < n){
    ll pos = lower_bound(a.begin(), a.end(), (k+1)/2) - a.begin();
    // deb(pos);
    // deb(k);
    if(pos == n)
      break;
    if(k == a[pos]) {
      a[pos] = -1;
      k *= 2;
      i = pos;
      count++;
      continue;
    }
    ll day = (ll)(ceil(log2(ceil((double)(a[pos])/(k*1.0)))))+1;
    // deb(day);
    count += day;
    i = pos;
    k = a[pos]*2;
    a[pos] = -1;
  }
  for(ll &i : a)
    if(i != -1)
      count++;
  cout << count << endl;
  // cout << "_____________" << endl;
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
10 3
1 2 4 5 5 8 10 11 12 24
*/