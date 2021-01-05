#include<bits/stdc++.h>
using namespace std;
#define int int64_t

signed main() {
  int n;
  cin >> n;
  vector<array<int, 3>> a(n);
  int t = 0, aa = 0;
  for(int i = 0; i < n; i++) {
    cin >> a[i][2] >> a[i][1];
    a[i][0] += a[i][2] + a[i][1];
    aa += a[i][2];
  }
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  int count = 0;
//  for (int i = 0; i < n; i++) {
//      cout << a[i][0] << ' ' << a[i][1] << ' ' << a[i][2] << endl;
//  }
  for(int i = 0; i < n; i++) {
    t += a[i][0];
    aa -= a[i][2];
    count++;
    if(t > aa) {
      break;
    } 
  }
  cout << count << '\n';
  return 0;
}
