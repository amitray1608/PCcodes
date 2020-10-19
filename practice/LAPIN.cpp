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
  map<char, int>a, b;
  int i = 0, n = (int)s.size();
  while(i < n/2)
    a[s[i++]]++;
  if(n&1)
    i++;
  while(i < n) 
    b[s[i++]]++;
  bool falg = true;
  for(auto ii : a) {
    if(ii.second != b[ii.first])
      falg = false;
  }
  cout << (falg ? "YES" : "NO") << endl;
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