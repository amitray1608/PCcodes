#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3 + 1;

int n, m;
vector<int>a, b;
int dp[maxn][maxn];
vector<int> anss;

int recc(int i, int j) {
  if(i < 0 or j < 0) return 0;
  int &ans = dp[i][j];
  if(ans != -1) return ans;
  ans = 0;
  if(a[i] == b[j]) {
    ans = recc(i - 1, j - 1) + 1;
  } else {
    ans = max(recc(i - 1, j), recc(i, j - 1));
  }
  return ans;
}

void trace(int i, int j) {
  if(i < 0 or j < 0) return;
  int ans = recc(i, j);
  if(a[i] == b[j] && ans == 1 + recc(i - 1, j -1)) {
    anss.push_back(a[i]);
    trace(i - 1, j - 1);
    return;
  }
  if(dp[i - 1][j] == ans) {
    trace(i - 1, j);
  } else {
    trace(i, j - 1);
  }
}

void solve() {
  cin >> n >> m;
  a.resize(n);
  b.resize(m);
  for(int &i : a) cin >> i;
  for(int &i : b) cin >> i;
  memset(dp, -1, sizeof dp);
  recc(n - 1, m - 1);
//  cout << dp[n - 1][m - 1] << '\n';
  trace(n - 1, m - 1);
  reverse(anss.begin(), anss.end());
  for(int i : anss) cout << i << ' ';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
//  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite

