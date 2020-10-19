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
  int n, m;
  cin >> n >> m;
  ll ans = 0;
  int a[m], curr = 1;
  for(int i = 0; i < m; i++) cin >> a[i];
  for(int i = 0; i < m; i++) {
    if(a[i] >= curr)
      ans += (a[i] - curr), curr = a[i];
    else
      ans += (n-a[i-1]) + a[i], curr = a[i];
  }
  cout << ans << endl;
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
