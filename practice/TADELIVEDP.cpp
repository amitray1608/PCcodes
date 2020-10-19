#include<bits/stdc++.h>
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
typedef long double dd;
const int MOD = 1e9 + 7;

int n, x, y;
const int MAXN = 1e5 + 4;
int dp[MAXN][MAXN];
int a[MAXN], b[MAXN];

int recc(int i, int j) {
  if(i == n) return 0;
  int &ans = dp[i][j];
  if(ans != -1) return ans;
  int A = j;
  if(A + 1 <= x) 
    ans = max(ans, (a[i] + recc(i + 1, j + 1)));
  int B = i - j;
  if(B + 1 <= y)
    ans = max(ans, (b[i] + recc(i + 1, j)));
  return ans;
}

void solve(){
  cin >> n >> x >> y;
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n; i++) cin >> b[i];
  memset(dp, -1, sizeof dp);
  int ans = recc(0, 0);
  cout << ans << '\n';
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1, tt = 0;
  //cin >> t;
  while(t--){
  //cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
}//Hajimemashite
