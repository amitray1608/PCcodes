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
  int a[n];
  for(int &i : a) cin >> i;
  int rem[3] = {0};
  for(int &i : a) rem[i%3]++;
  if(~n&1 and rem[0] == rem[1] + rem[2])
    cout << "Yes" << endl;
  else if(n&1 and abs(rem[0] - rem[1] - rem[2]) == 1)
    cout << "Yes" << endl;
  else 
    cout << "No" << endl;
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