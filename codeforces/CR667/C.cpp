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
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> ans;
  int maxi = 1e9;
  if(n == 2) {
    cout << x << ' ' << y << endl;
    return;
  }

  for(int i = 1; i <= x; i++) {
    for(int j = 0; j <= (y-x); j++) {
      int count = 0, s = i;
      vector<int> a;
      for(int k = 0; k < n; k++) {
        a.push_back(s);
        if(s == x or s == y)
          count++;
        s += j;
      }
      if(count == 2 and *max_element(a.begin(), a.end()) < maxi) {
        maxi =  *max_element(a.begin(), a.end());
        ans = a;
      }
    }
  }
  for(int &i : ans)
    cout << i << ' ';
  cout << endl;
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