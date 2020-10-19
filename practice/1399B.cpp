//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void solve() {
  int n;
  cin >> n;
  int a[n], b[n];
  for(int &i : a) cin >> i;
  for(int &i : b) cin >> i;
  ll ans = 0;
  int minia = *min_element(a, a+n);
  int minib = *min_element(b, b+n);
  for(int i = 0; i < n; i++) {
    if(a[i] == minia and b[i] == minib) continue;
    if(a[i] == minia) {
      ans += b[i]-minib;
    } else if(b[i] == minib) {
      ans += a[i] - minia;
    } else {
      int x = (a[i] - minia);
      int y = (b[i] - minib);
      ans += max(x, y);
    }
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(10);
  int t = 1;
  cin >> t;
  for(int tt = 1; tt <= t; tt++) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  