
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int n;
    cin >> n;
    vector<int> a(n);
    int maxi = 0, mini = 105;
    for (int &i : a) {
      cin >> i;
      maxi = max(i, maxi);
      mini = min(i, mini);
    }
    int ans = 0;
    int rmax = 105;
    int rmin = 105;
    for (int i = 0; i < n; i++) {
      if (a[i] == maxi) {
        rmax = i;
      }
      if (a[i] == mini) {
        rmin = i;
      }
    }
    int left = min(rmax, rmin);
    int right = max(rmax, rmin);
    ans = min(left + n + 1 - right, min(right + 1, n - left));
    cout << ans << '\n';
  }	
  return 0;
} //Hajimemashite

