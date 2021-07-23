
#include<bits/stdc++.h>

using namespace std;
#define int int64_t

const int MOD = 1e9 + 7;
const int maxn = 2e5 + 1;
int dp[maxn];

int recc(int x) {
  if (x < 0) return 1;
  if (!x) return 2;
  int &ans = dp[x];
  if (ans != -1) return ans;
  ans =  (recc(x - 9) + recc(x - 10)) % MOD;
  return ans;
}


signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int t = 1;
  cin >> t;
  memset(dp, -1, sizeof dp);
  for (int tt = 1; tt <= t; ++tt) {
    string s;
    int n, m;
    cin >> s >> m;
    n = (int)s.size();
    vector<int> dig(10, 0);
    for (char c : s) {
      dig[c - '0']++;
    }
    /*
    for (int i = 0; i < m; i++) {
      int nine = dig[9];
      for (int j = 9; j >= 1; j--) {
        dig[j] = dig[j - 1];
      }
      n = (n + nine) % MOD;
      dig[0] = nine;
      dig[1] = (dig[1] + nine) % MOD;
    }
    */
    int res = 0;
    for (int i = 0; i < n; i++) {
      res = (res + recc(m - (10 - (s[i] - '0')))) % MOD;
    }
    cout << res << '\n';
  }
  return 0;
} //Hajimemashite

