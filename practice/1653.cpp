
#include<bits/stdc++.h>

using namespace std;
#define int int64_t

const int N = 20;
const int maxn = 1 << N;
int dp[maxn];
int n, W;
vector<int> a;
int res = INT_MAX;

int recc(int mask, int curr, int w) {
  if (mask == (1 << n) - 1) {
    res = min(res, curr);
    return 0;
  }
  int &ans = dp[mask];
  if (ans != -1) {
    return ans;
  }
  ans = INT_MAX;
  for (int j = 0; j < n; j++) {
    if (!(mask & (1 << j))) {
      if (w + a[j] > W) curr++, w = 0;
      ans = min(ans, curr + recc((mask | (1 << j)), curr, w + a[j]));
    }
  }
  return ans;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  cin >> n >> W;
  a.resize(n);
  for (int &i : a) {
    cin >> i;
  }
  int ans = recc(0, 1, 0);
  cout << ans << '\n';
  return 0;
} //Hajimemashite

