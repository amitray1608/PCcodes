
#include<bits/stdc++.h>

using namespace std;
#define int int64_t
const int N = 20;
const int maxn = (1 << 20);
int dp[maxn];
vector<vector<int>> adj;
int n;

int recc(int mask, int i) {
  if (mask == (1 << n) - 1) {
    return 1;
  }
  int &ans = dp[mask];
  if (ans != -1) {
    return ans;
  }
  ans = 0;
  for (int j = 0; j < n; j++) {
    if (!(mask & (1 << j)) and adj[j][i]) {
      ans += recc((mask ^ (1 << j)), i + 1);
    }
  }
  return ans;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    cin >> n;
    adj.assign(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> adj[i][j];
      }
    }
    memset(dp, -1, sizeof dp);
    cout << recc(0, 0) << '\n';
  }	
  return 0;
} //Hajimemashite

