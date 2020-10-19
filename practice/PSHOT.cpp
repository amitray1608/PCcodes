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
  string s;
  cin >> s;
  int status = 0;
  int count = 0, a = 0, b = 0, A = n, B = n;
  for(char i : s) {
    if(status) {
      A--;
      if(i == '1') a++;
    } else {
      B--;
      if(i == '1') b++;
    }
    status ^= 1;
    count++;
    if(a > b + B or b > a + A)
      break;
  }
  cout << count << endl;
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