
#include<bits/stdc++.h>

using namespace std;
#define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int n, k;
  cin >> n >> k;
  vector<array<int, 3>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i][0];
    a[i][1] = i;
    a[i][2] = 0;
  }
  sort(a.begin(), a.end());
  if (k >= n) {
    int curr = k / n;
    k %= n;
    for (int i = 0; i < n; i++) 
      a[i][2] = curr;
  } 
  int i = 0;
  while (k--) {
    a[i][2]++;
    i++;
  }
  sort(a.begin(), a.end(), [&](auto x, auto y){
        return x[1] < y[1];
      });
  for (auto ii : a) {
    cout << ii[2] << '\n';
  }
  return 0;
} //Hajimemashite

