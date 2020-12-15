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
  int n, k;
  cin >> n >> k;
  int a[n];
  for(int &i : a) cin >> i;
  while(k--) {
    int x;
    cin >> x;
    int l = 0, h = n-1, flag = 0;
    while(l <= h) {
      int mid = l + (h-l) / 2;
      if(a[mid] >= x) {
        h = mid-1;
        flag = 1;
      } else {
        l = mid+1;
      }
    }
    cout << (flag ? l+1 : n+1) << endl;
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
