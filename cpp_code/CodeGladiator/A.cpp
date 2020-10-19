//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
int dp[21][11], a[11][21];
int p, d;
bool check[11];
int recc(int s, int e) {
    if (s >= p) return 0;
    if (dp[s][e + 1] != -1) 
        return dp[s][e + 1];
    int r(INT_MAX);
    for (int i = 0; i < d; i++) {
        if (!check[i]) {
            check[i] = 1;
            r = min(r, recc(s + 1, i) + a[i][s]);
            check[i] = 0;
        }
        else if (i == e) 
            r = min(r, recc(s + 1, i) + a[i][s]);
    }
    dp[s][e + 1] = r;
    return dp[s][e + 1];
}

void solve(){
  cin >> p >> d;
  for(int i = 0; i < d; i++)
    for(int j = 0; j < p; j++)
      cin >> a[i][j];
  int ans = INT_MAX;
  memset(dp, -1, sizeof dp);
  for (int i = 0; i < d; i++) {
      check[i] = 1;
      ans = min(ans, recc(1, i) + a[i][0]);
      check[i] = 0;
  }
  cout << ans << "\n";
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while(t--){
    //tt++;
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  