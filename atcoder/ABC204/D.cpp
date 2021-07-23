
#include<bits/stdc++.h>

using namespace std;
const int maxn = 101;
const int maxSum = 100005;
int dp[maxn][maxSum];
int n;
int a[maxn];

int recc(int i, int curr, int total) {
  if (i < 0) 
    return abs((total - curr) - curr);
  int &ans = dp[i][curr];
  if (ans != -1) return ans;
  ans = 0;
  ans = min(recc(i - 1, curr + a[i], total), recc(i - 1, curr, total));
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  cin >> n;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  memset(dp, -1, sizeof dp);
  int ans = recc(n - 1, 0, sum);
  cout << ans + ((sum - ans) / 2)  << '\n'; 
  return 0;
} //Hajimemashite


