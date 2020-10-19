//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void solve(){
  ll n, k;
  cin >> n >> k;
  vector<ll>a(n);
  for(ll &i : a) cin >> i;
  sort(a.begin(), a.end());
  ll count = 0;
  if(a[0] <= k)
    cout << n << endl;
  else{

    count = (ll)(ceil(log2(ceil((double)(a[0])/(k*1.0)))))+1;
    // deb(count);
    count += (n-1);
    cout << count << endl;
  }
  // for(int i = 0; i < n; i++) {

  // }
  // cout << ceil(3/2.0) << endl;
  // cout << count << endl;
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