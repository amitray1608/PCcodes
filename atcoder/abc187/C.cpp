#include<bits/stdc++.h>
using namespace std;
#define int int64_t

signed main() {
  int n;
  cin >> n;
  int sum = 0;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    int u, v;
    cin >> u >> v;
    sum -= u;
    a[i] = u + u + v;
  }
  
  sort(a.begin(), a.end());
  int ans = 0;
  while(sum <= 0) {
    sum += a.back();
    a.pop_back();
    ans++;
  }

  cout << ans << '\n';
  return 0;
}
