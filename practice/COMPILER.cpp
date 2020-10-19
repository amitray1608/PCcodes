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
  string s;
  cin >> s;
  int sum = 0, n = (int)s.size(), ans = 0;
  for(int i = 0; i < n; i++) {
    (s[i] == '<') ? sum++ : sum--;
    if(sum < 0) break;
    if(sum == 0)
      ans = i+1;
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