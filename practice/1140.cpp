
#include<bits/stdc++.h>

using namespace std;
#define int int64_t

const int maxn = 3e5 + 1;
int n;
int dp[maxn];
vector<array<int, 3>> a;

int recc(int i) { 
  if (i >= n) return 0;
  int &ans = dp[i];
  if (ans != -1) return ans;
  int next = upper_bound(a.begin(), a.end(), array<int, 3>{a[i][1] + 1, -1, -1}) - a.begin() - 1;
  ans = max(recc(i + 1), recc(next + 1) + a[i][2]);
  return ans;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    for (auto &j : a[i]) cin >> j;
  }
  sort(a.begin(), a.end());
//  for (auto i : a) {
//    for (int j : i) cout << j << ' ';
//    cout << '\n';
//  } 
  memset(dp, -1, sizeof dp);
  cout << recc(0) << '\n';
} //Hajimemashite

