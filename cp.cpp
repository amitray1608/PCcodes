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
  int n;
  cin >> n;
  double p;
  cin >> p;
  double ans = 1.0;
  while(n > 0) {
    if(n&1)
      ans = ans * (1-p)  + (1-ans) * p;
    p = p  * (1-p) + (1-p) * p;
    n >>= 1;
  }
  cout << fixed <<  setprecision(10) << ans << endl;
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