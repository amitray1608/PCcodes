#include <bits/stdc++.h>

using namespace std;
#define int int64_t

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, s;
  cin >> n >> s;
  vector<int> a(n);
  for (int &i : a) cin >> i;
  int count = 0, sum = 0, j = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
    while (sum - a[j] >= s) {
      sum -= a[j++];
    }
    if (sum >= s) count += j + 1;
  }
  cout << count << '\n';

  return 0;
}
