
#include<bits/stdc++.h>

using namespace std;

string s, t;
int n, m;
const int maxn = 2e3 + 1;
int dp[maxn][maxn];

int recc(int i, int j) {
  if (i == -1) return j + 1;
  if (j == -1) return i + 1;
  int &ans = dp[i][j];
  if (ans != -1) return ans;
  ans = 0;
  if (s[i] == t[j]) 
    return ans = recc(i - 1, j - 1);
  ans = 1 + min({recc(i - 1, j), recc(i, j - 1), recc(i - 1, j - 1)});
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int T = 1;
  cin >> T;
  for (int tt = 1; tt <= T; ++tt) {
    cin >> s >> t;
    n = (int)s.size();
    m = (int)t.size(); 
    memset(dp, -1, sizeof dp);
    cout << recc(n - 1, m - 1) << '\n';
  }
  return 0;
} //Hajimemashite

