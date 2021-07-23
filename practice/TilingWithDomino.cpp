
#include<bits/stdc++.h>

using namespace std;

#define int int64_t
const int MOD = 1e9 + 7;
const int maxn = 1e5 + 1;
int dp[maxn];
int n;

int recc(int i) {
  if (i == 0) return 3;
  int &ans = dp[i];
  if (ans != -1) return ans;
  ans = 3;
  ans = (ans * recc(i - 2));
  return ans;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  cin >> n;
  memset(dp, -1, sizeof dp);
  if (n&1) {
    cout << 0 << '\n';
    return 0;
  }
  cout << recc(n - 1) << '\n';
  return 0;
} //Hajimemashite

