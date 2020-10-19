#include<bits/stdc++.h>
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
using namespace std;
typedef unsigned long long ll;
typedef long double dd;
const int MOD = 1e9 + 7;

void solve(){
  ll x, y, a, b;
  cin >> x >> y >> a >> b;
  ll count = 0;
  while(x < y) {
    count += 2;
    x *= a;
    x += b;
  }
  cout << count << '\n';
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1, tt = 0;
  //cin >> t;
  while(t--){
  //cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
}//Hajimemashite
