
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  vector<long long> dp(102, 0);
  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;
  for (int i = 4; i <= 100; i++) {
    dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
  } 
    cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << dp[n + 1] << '\n';
  }
  return 0;
} //Hajimemashite
