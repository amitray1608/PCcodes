#include<bits/stdc++.h>
#define int unsigned long long

using namespace std;

signed main() {
  int n, t;
  cin >> n >> t;
  vector<int> a(n);
  for(int &i : a) cin >> i;
  
  auto check = [&](int x) {
    int count = 0LL;
    for(int i = 0; i < n; i++) {
      count += x/a[i];
    }
    return count >= t;
  };

  int l = 0LL, r = 1e18 + 1;
  while(l <= r) {
    int mid = l + (r - l) / 2LL;
//    cout << mid << ' ';
    if(check(mid)) 
      r = mid - 1LL;
    else
      l = mid + 1LL;
  } 
  cout << endl;
  cout << l << endl;
  return 0;
}
