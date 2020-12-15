#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 1;
const int maxn = 101;

int dp[maxn][MAXN], n;
vector<int> a;

int recc(int i, int j) {
  if(i == 0) {
    if(j == 0)
      return dp[i][j] = 1;
    else
      return 0;
  }
  if(j < 0 or i < 0) return 0;
  int &ans = dp[i][j];
  if(ans != -1) return ans;
  ans = recc(i - 1, j - a[i]) | recc(i - 1, j);
  return ans;
}

int main() {
  int n;
  cin >> n;
  a.resize(n + 1);
  for(int i = 1; i <= n; i++) cin >> a[i];
  memset(dp, -1, sizeof dp);
  int sum = accumulate(a.begin(), a.end(), 0);
  dp[0][0] = 1;
  int res = recc(n, sum);
  set<int> ans;
  for(int i = 0; i <= n; i++) {
    for(int j = 0; j < sum + 1; j++) {
      cout << dp[i][j] << ' '; 
      if(dp[i][j] == 1)
        ans.insert(j);
    } cout << endl;
  }
  cout << ans.size() << endl;
  for(int i : ans) cout << i << ' ';
  cout << endl;
  return 0;
}
