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
  int diff[n] = {0};
  int maxi = 1;
  for(int j = 1; j < n; j++) {
    diff[j] = a[j]-a[j-1];
  }
  int count = 1;
  for(int i = 1; i < n; ) {
    bool flag = true;
    while(i + 1 < n and diff[i] == diff[i+1]) {
      count++;
      i++;
      flag = false;
    }
    if(flag)
      i++;
    maxi = max(count, maxi);
    count = 1;
  }
  cout << maxi+1 << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(10);
  int t = 1;
  cin >> t;
  for(int tt = 1; tt <= t; tt++) {
    cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  