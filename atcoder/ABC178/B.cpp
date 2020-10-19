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
  string s, t;
  cin >> s >> t;
  int mini = INT_MAX;
  int n = (int)s.size(), m = (int)t.size();
  for(int i = 0; i < n-m+1; i++) {
    int count = 0;
    for(int j = 0; j < m; j++) {
      if(s[i+j] != t[j])
        count++;
    }
    mini = min(mini, count);
  }
  cout << mini << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(10);
  int t = 1;
 // cin >> t;
  for(int tt = 1; tt <= t; tt++) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  