
#include<bits/stdc++.h>

using namespace std;
#define int int64_t

const int maxn = 5e5 + 1;
int dp[maxn];
int n;
vector<array<int, 2>> a;

int recc(int i) {
  if (i >= n) return 0;
  int &ans = dp[i];
  if (ans != -1) return ans;
  int j = upper_bound(a.begin(), a.end(), array<int, 2> {a[i][1] + 1, -1}) - a.begin() - 1;
  ans = max(recc(i + 1), recc(j + 1) + 1);
  return ans;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  cin >> n;
  a.resize(n);
  for (auto &i : a) {
    cin >> i[0] >> i[1];
  }
  sort(a.begin(), a.end()); 
  memset(dp, -1, sizeof dp);
  cout << recc(0) << '\n';
  return 0;
} //Hajimemashite

