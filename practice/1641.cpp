#include<bits/stdc++.h>
#define ll long long
using namespace std;

signed main() {
  int n, x;
  cin >> n >> x;
  
  vector<array<int, 2>> a(n);
  for(int i = 0; i < n; i++) 
    cin >> a[i][0], a[i][1] = i + 1;

  sort(a.begin(), a.end());

  for(int i = 0; i < n - 2; i++) {
    for(int j = i + 1; j < n - 1; j ++) {
      int left = x - a[i] - a[j]; 
      if(binary_search(a.begin() + j + 1, a.end(), left)) {
        auto p = upper_bound(a.begin() + j + 1, a.end(), left) - a.begin() - 1;
        while(p >= 0 and (p == a[i][1] or p == a[j][1])) p--;
        cout << a[i][1] << ' ' << a[j][1] << ' ' << a[p][1] << endl; 
      }
  return 0;
}
