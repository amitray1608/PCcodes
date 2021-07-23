
#include<bits/stdc++.h>

using namespace std;
#define int int64_t

const int mod = 1e9 + 7;
const int maxn = 1e3 + 2;
int dp[maxn][maxn];
int n, k;

int recc(int i, int j) {
  if (!i) return 0;
  int &ans = dp[i][j];
  if (ans != -1) return ans;
  if (i == 1 or j == 0) {
    ans = 1;
  } else {
   ans = (recc(i, j - 1) + recc(i - 1, n - j)) % mod;
  }
  return ans;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    cin >> n >> k;
    memset(dp, -1, sizeof dp);
    recc(k, n);
   cout << dp[k][n] << '\n'; 
  }
  return 0;
} //Hajimemashite

