//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

vector<vector<int>>cost;

int recc(int n) {
  int N = (int)pow(2, n);
  int dp[N];
  for(int i = 0; i < N; i++) dp[i] = INT_MAX;
  dp[0] = 0;
  for(int mask = 0; mask < N; mask++) {
    int x = __builtin_popcount(mask);
    cout << "---------------" << endl;
    deb(mask);
    deb(x);

    for(int j = 0; j < n; j++) {
      int p = (1 << j);
      deb(p);
      if((mask & (1 << j)) == 0) {
        dp[mask | (1 << j)] = min(dp[mask | (1 << j)], dp[mask] + cost[x][j]);
      }
    }
    for(int &i : dp)
      cout << i << ' ';
    cout << endl;
    cout << "---------------" << endl;
  }
  return dp[N-1];
}

void solve(){
  int n;
  cin >> n;
  cost.resize(n, vector<int>(n, 0));
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cin >> cost[i][j];
  int ans = recc(n);
  cout << ans << endl;

}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while(t--){
    //tt++;
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  

/*
4
9 4 2 5 
2 5 1 6
0 23 5 3
3 9 2 1
*/
