#include<bits/stdc++.h>

using namespace std;
#define int int64_t

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, s;
  cin >> n >> s;
  vector<int> w(n);
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    cin >> w[i];
  }
  for (int j = 0; j < n; j++) {
    cin >> c[j];
  }

  int maxi = 0, j = 0, sum = 0, cost = 0;
  for (int i = 0; i < n; i++) {
    sum += w[i];
    cost += c[i];
    while (sum > s) {
      cost -= c[j];
      sum -= w[j];
      j++;
    }
    if (cost > maxi) maxi = cost;
  }
  cout << maxi << '\n';

  return 0;
} //Hajimemashite
