#include<bits/stdc++.h>

using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;

void solve() {
  int b, h, n;
  cin >> b >> h >> n;
  bool ok = true;
  ll count = 1;
  while(~b&1) {
    b /= 2;
    count *= 2;
  }
  while(~h&1) {
    h /= 2;
    count *= 2;
  }
  if(count >= n){
    ok = true;
  } else{
    ok = false;
  }
  cout << (ok ? "Yes" : "No") << '\n';
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
