#include<bits/stdc++.h>
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
typedef long double dd;
const int MOD = 1e9 + 7;
const int MAXN = 5e3+2;
int n, k;
int dp[MAXN][MAXN], pre[MAXN][MAXN];


void solve(){
  cin >> n >> k;
  memset(dp, -1, sizeof dp);
  memset(pre, 0, sizeof dp);
  vector<int> a(n);
  for(auto &i : a) cin >> i;
  for(int i = 0; i < n - 1; i++) {
    pre[i][i] = a[i];
    for(int j = i + 1; j < n; j++) {
      pre[i][j]
    }
  }
  recc(n-1, );
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
