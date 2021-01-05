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
  vector<ll> a(n);
  for(ll &i : a) cin >> i;
  ll ans = 0;
  sort(a.begin(), a.end());
  for(int i = n - 1; i >= 0; i--)
    ans += (i * a[i]) - ((n - i - 1)  * a[i]);
  cout << ans << '\n';
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
