//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
const int maxn = 1 << 9;

int check(int ans, vector<int> &a, vector<int> &b) {
  for (int x: a) {
    bool possible = false;
    for (int y: b) {
      int c = x & y;
      if ((c & ans) == c) {
        possible = true;
         break;
      }
    }
    if (!possible) return false;
  }
  return true;
}
 

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for(int &i : a) cin >> i;
  for(int &i : b) cin >> i;
  for(int i = 0; i < maxn; i++) {
    if(check(i, a, b)) {
      cout << i << endl;
      return;
    }
  }
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