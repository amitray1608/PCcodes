
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort (a, a + n);
  int sum = 0;
  cin >> sum;
  for (int i = 0; i < n; i++) {
    int x = sum - a[i];
    int l = 0, h = n-1;
    while(l <= h) {
      int mid = l + (h - l) / 2;
      if(a[mid] == x) {
        cout << a[i] << ' ' << x << '\n';
        return;
      }
      if(a[mid] > x) {
        h = mid-1;
      } else {
        l = mid+1;
      }
    }
  }
  cout << "NO sol found" << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
  //cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite


