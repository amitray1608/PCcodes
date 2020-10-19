#include<bits/stdc++.h>
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
typedef long double dd;
const int MOD = 1e9 + 7;
#define ff first
#define ss second

void solve(){
  int n;
  cin >> n;
  vector<string> s(n);
  for(string &i : s) cin >> i;
  int count = 0;
  vector<vector<pair<int, int>>> dp(n+1, vector<pair<int, int>>(n+1, {0, 0}));
  for(int i = 0; i < n+1; i++) {
    dp[n][i].ff = 1, dp[n][i].ss = 1;
    dp[i][n].ss = 1, dp[i][n].ff = 1;
  }
  for(int i = n - 1; i >= 0; i--) {
    for(int j = n - 1; j >= 0; j--) {
      int x = 0;
      if(s[i][j] == '.') {
        if(dp[i][j + 1].ff == 1) dp[i][j].ff = 1, x++;
        if(dp[i + 1][j].ss == 1) dp[i][j].ss = 1, x++;
      }
      if(x == 2) count++;
    }
  }
  /*
  for(int i = 0; i < n+1 ; i++) {
    for(int j = 0; j < n+1; j++) cout << "(" << dp[i][j].ff << ',' << dp[i][j].ss << ") "; 
    cout << endl;
  }
  */
  cout << count << '\n';
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1, tt = 0;
  cin >> t;
  while(t--){
  //cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
}//Hajimemashite

/*
1
5
..#..
....#
.....
.##.#
...#.
*/
