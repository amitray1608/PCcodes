
#include<bits/stdc++.h>

using namespace std;
#define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int n;
  cin >> n;
  vector<int> a(2 * n);
  for (int &i : a) cin >> i;
  int dp[n + 1][2];
  memset(dp, -1, sizeof dp); 
  for (int j = 0; j < 2 * n; j++) {
    int i = a[j];
    if (dp[i][0] == -1) dp[i][0] = j + 1;
    else dp[i][1] = j + 1;
  }
  int sum = 0;
  int curra = 1, currb = 1;
  for (int i = 1; i <= n; i++) {
    sum += abs(dp[i][0] - curra);
    sum += abs(dp[i][1] - currb);
    curra = dp[i][0];
    currb = dp[i][1];
  }
  cout << sum << '\n';
  return 0;
} //Hajimemashite

