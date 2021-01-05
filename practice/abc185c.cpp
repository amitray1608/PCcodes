#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll dp[201][12];
int n;

ll recc(int i, int j) {
  if(i == n) return 0;
  if(j == 11) return 1;
  ll &ans = dp[i][j];
  if(ans != -1) return ans;
  ans = recc(i + 1, j) + recc(i + 1, j + 1);
  return ans;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  cin >> n;
  memset(dp, -1, sizeof dp);
  cout << recc(0, 0) << "\n";
  return 0;
}
