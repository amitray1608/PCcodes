//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

ll fact[siz] = {0};

void solve(){
  ll a, b;
  cin >> a >> b;
  ll ans = 1;
  if(a >= b) {
    cout << 0 << endl;
    return;
  }
  for(int i = 1; i <= a; i++) {
    ans = (ans*i)%b;
  }
  cout << ans << endl;
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