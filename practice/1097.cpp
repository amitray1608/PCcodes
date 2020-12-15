#include<bits/stdc++.h>

using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long double ld;
const int MOD = 1e9 + 7;
#define int long long
const int MAXN = 5e3 + 1;
const int inf = 1e18;
int dp[MAXN][MAXN];
vector<int> a;
int n;

int recc(int i, int j) {
  if(i == j) return dp[i][j] = a[i];
  int &ans = dp[i][j];
  if(ans != inf) return ans;
  ans = a[i] - recc(i + 1, j);
  ans = max(ans, a[j] - recc(i, j - 1));
  return ans;
}

void solve() {
  cin >> n;
  a.resize(n);
  int sum = 0;
  for(int &i : a) cin >> i, sum += i;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) dp[i][j] = inf;
  int ans = recc(0, n - 1) + sum;
//  for(int i = 0; i < n; i++) {
//    for(int j = 0; j < n; j++) cout << dp[i][j] << ' ';
//    cout << endl;
//  }
  cout << ans / 2;
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1, tt = 0;
  //cin >> t;
  while(t--){
    //cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite
