
#include<bits/stdc++.h>

using namespace std;
#define int int64_t
const int maxn = 1e6 + 3;
int dp[maxn];

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &i : a) {
    cin >> i;
  }
  memset(dp, 0, sizeof dp);
  for (int i = 1; i < maxn; i++) {
    dp[i] = i + 1;
  }
  for (int i = 2; i * i < maxn; i++) {
    for (int j = i * i
  for (int i = 0; i < n; i++) {
    
  }
  return 0;
} //Hajimemashite

