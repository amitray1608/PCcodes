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
  int n, m;
  cin >> n >> m;
  int a = 0, b = 0;

  a = n/9;
  n %= 9;
  b = m/9;
  m %= 9;

  if(n != 0)
    a++;
  if(m != 0)
    b++;
  
  if(a >= b) {
    cout << 1 << ' ' << b << endl;
  } else {
    cout << 0 << ' ' << a << endl;
  }

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