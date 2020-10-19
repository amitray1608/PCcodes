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
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int o = 0, z = 0;
  for(char c : s)
    (c == '1' ? o++ : z++);
  
  int x = n/k;
  if(o % x != 0 or z % x != 0 ) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }

  string ans = "", one = "";
  for(int i = 0; i < (z/x); i++) {
    one += '0';
  }
  for(int i = 0; i <  (o/x); i++) {
    one += '1';
  }
  // deb(one);
  string two = one;
  reverse(two.begin(), two.end());
  for(int i = 0; i < n/k; i++) {
    if(i&1)
      ans += two;
    else
      ans += one;
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