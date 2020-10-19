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
  ll k, fir, sec;
  cin >> k >> fir >> sec;
  ll two[4] = {2, 4, 8, 6};
  ll x = fir + sec + (fir + sec)%10;
  ll q = (k - 3) / 4, r = (k - 3) % 4;
  for(int i = 0; i < 4; i++) {
    x += ((two[i] * (fir + sec))%10)*q;
  }
  for(int i = 0; i < r; i++) {
    x += ((two[i] * (fir + sec))%10);
  }
  cout << ((x%3) ? "NO" : "YES") << endl;
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
