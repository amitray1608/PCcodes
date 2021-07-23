
#include<bits/stdc++.h>

using namespace std;
const int maxn = 1e3 + 1;
int dp[maxn][maxn];
string s;

int recc(int l, int r) {
  //if odd
  if (l == r) {
    return 1;
  }
  //if even
  if (l + 1 == r and s[l] == s[r]) {
    return 2;
  }
  int &ans = dp[l][r];
  // if already calculated
  if (ans != -1) return ans;
  ans = 0;
  // if there's a character match
  if (s[l] == s[r]) {
    return ans = recc(l + 1, r - 1) + 2;
  }
  // if no character matches then move either left or right.
  ans = max({recc(l + 1, r), recc(l, r - 1)});
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  cin >> s;
  int n = (int)s.size();
  memset(dp, -1, sizeof dp);
  cout << recc(0, n - 1) << '\n';
  return 0;
} //Hajimemashite

