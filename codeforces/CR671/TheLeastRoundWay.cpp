#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
#define ff first
#define ss second
typedef long long ll;
typedef double dd;
const int MOD = 1e9 + 7;

void solve(){
  int n;
  cin >> n;
  vector<vector<pair<int, int>>>a(n, vector<pair<int, int>>)dp(n, vector<pair<int, int>>(n, {0,0}));
  for(int i = 0; i < n; i++) {
    for(auto &j : i) {
      cin >> j;
      int x = j, count = 0;
      while(x%2 ==0) {
        count++;
        x/=2;
      }
      dp[i]
      count = 0;
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1, tt = 0;
  //cin >> t;
  while(t--){
    //tt++;
    //cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
