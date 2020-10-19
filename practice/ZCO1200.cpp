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
  vector<int> a(n+1);
  for(int i = 1; i < n+1; i++) {
    cin >> a[i];
  }
  int deep = 0, deeppos = 0, maxi = 0, maxipos = 0, pos = 0, sum = 0, prev = 0;
  int i = 1;
  for(; i <= n; i++) {
    if(sum == 0)
      prev = pos, pos = i;
    (a[i] == 1) ? sum++ : sum--;
    if(deep < sum)
        deep = sum, deeppos = i;
    if(prev) {
      if(pos - prev > maxi)
        maxi = pos - prev, maxipos = prev;
    }
  }
  if(i-pos > maxi)
    maxi = i - pos, maxipos = pos;
  
  cout << deep << ' ' << deeppos << ' ' << maxi << ' '  << maxipos << endl;;
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