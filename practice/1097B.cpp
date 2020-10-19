#include<bits/stdc++.h>
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
typedef long double dd;
const int MOD = 1e9 + 7;

const int MAXN = 16;
int n;
int dp[n + 1][(1 << n)+1];

bool recc(int i, int deg, int mask) {
  if((deg%360) == 0 and  == n) return true;
  if(dp[i][mask] != -1) return dp[i][mask];
  bool flag = false;
  for(int j = 0; j < n; j++) {
    
  }
}


void solve(){
  cin >> n;
  memset(dp, -1, sizeof dp);
  cout << (recc(0, 0, 0) ? "YES" : "NO") << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1, tt = 0;
  //cin >> t;
  while(t--){
  //cout << "Case #" << ++t << ": ";
    solve();
  }
  return 0;
}//Hajimemashite
