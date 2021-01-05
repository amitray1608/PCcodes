#include<bits/stdc++.h>

using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;

void solve() {
  ll n, Z, O;
  cin >> n >> Z >> O;
  int currz = 0, curro = 1;
  ll ans = 0, anss = 0;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if(currz != x) {
      if(x) ans += O;
      else ans += Z;
    } 
    if(curro != x) {
      if(x) anss += O;
      else anss += Z;
    }
    currz ^= 1;
    curro ^= 1;
  }
  cout << min(ans, anss) << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1, tt = 0;
  cin >> t;
  while(t--){
    //cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite

