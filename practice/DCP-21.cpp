#include<bits/stdc++.h>
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
typedef long double dd;
const int MOD = 1e9 + 7;

const int MAXN = 102;
vector<double> dp(MAXN);

void pre() {
  dp[1] = log2(1);
  for(int i = 2; i < MAXN; i++) {
    dp[i] = dp[i-1] + (double)(log2(i));
  }
}

void solve(){
  double n, m;
  cin >> m;
  n = m * 2 - 1;
  double p;
  cin >> p;
  if(p == 1) {
    cout << 1.000 << endl;
    return;
  }
  int N = (int)n, M = (int)m;
  double ans = 0;
  for(int i = M; i <= N; i++) {
    double pw = dp[N] - dp[N - i] - dp[i] + i * log2(p) + (n - i) * log2(1 - p);
    ans += pow(2.0, pw);
  }
  cout << ans << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1, tt = 0;
  cout << fixed << setprecision(3) << endl;
  cin >> t;
  pre();
  while(t--){
  cout << "Case " << ++tt << ": ";
    solve();
  }
  return 0;
}//Hajimemashite
