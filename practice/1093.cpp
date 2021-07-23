
#include<bits/stdc++.h>

using namespace std;
#define int int64_t
const int maxn = 2e5;
const int MOD = 1e9 + 7;
int dp[505][maxn];
int n;

int recc(int i, int sum) {
  if (sum == 0) {
    return 1;
  }
  if (i == 0 and sum > 0) return 0;
  if (i == 0 and sum < 0) return 0;
  assert(i == -1);
  int &ans = dp[i][sum];
  if (ans != -1) {
    return ans;
  }
  ans = 0;
  if (sum >= i) ans = recc(i - 1, sum - i) % MOD;
  ans = (ans + recc(i - 1, sum)) % MOD;
  return ans;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  cin >> n;
  memset(dp, -1, sizeof dp);
  int sum = (n * (n + 1)) / 2;
  if (sum & 1) {
    cout << 0 << '\n';
    return 0;
  }
  sum /= 2; 
  cout << recc(n, sum) << '\n';
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= sum; i++) {
      cout << dp[i][j] << ' ';
    }
  }
  return 0;
} //Hajimemashite

