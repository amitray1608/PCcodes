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
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  if(!((n-1) % x) and !((m-1) % y))
    cout << "Chefirnemo" << endl;
  else if(!((n-2) % x) and !((m-2) % y) and n > 1 and m > 1)
    cout << "Chefirnemo" << endl;
  else
    cout << "Pofik" << endl;
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