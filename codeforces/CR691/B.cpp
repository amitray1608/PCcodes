#include<bits/stdc++.h>

using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  if(n <= 2) {
    cout << 4 << endl;
  } else {
    ll count = 0;
    //formula source - internet
    if(n&1) count = (1 + ((3 * n * (n + 4) + 2 - (-1) * (n * (n + 4) + 2 ))) / 8);
	  else count = (1 + ( 3 * n * (n + 4) + 2 - (n * (n + 4) + 2)) / 8);
    cout << count << '\n';
  }
}

int main(){ 
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1, tt = 0;
  //cin >> t;
  while(t--){
    //cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite
