#include<bits/stdc++.h>

using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
using ll =  long long;
typedef long double ld;
const ll MOD = 1e9 + 7;

void solve() {
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n), b(m), c(n);
  for(ll i = 0; i < n; i++) {
    cin >> a[i];
  }
  for(int i = 0; i < m; i++) {
    cin >> b[i];
  }
  sort(a.begin(), a.end());
  c[0] = a[0];
  for(int i = 1; i < n; i++)
    c[i] = abs(a[i] - a[i - 1]);
  ll gcd = 0;
  for(int i = 1; i < n; i++) gcd = __gcd(c[i], gcd);
  for(int i = 0; i < m; i++) {
    cout << __gcd(c[0] + b[i], gcd) << ' ';
  } 
  cout << endl;
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  ll t = 1, tt = 0;
  //cin >> t;
  while(t--){
    //cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite
