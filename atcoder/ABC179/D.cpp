#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef double dd;
const int MOD = 998244353;
#define ff first
#define ss second

template<typename T>
string to_string(vector<T> v) {
  string res;
  for(auto &i : v)
    res += char('0'+i), res += ' ';
  return res;
}
 
template<class A> void vbug(A x) {
  cout << to_string(x) << endl;
}

void solve(){
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>>v(k);
  for(int i = 0; i < k; i++){
    cin >> v[i].ff >> v[i].ss;
  }
  vector<int>dp(n+1, 0), pre(n+1, 0);
  dp[1] = pre[1] = 1;
  for(int i = 2; i <= n; i++) {
    int tmp = 0;
    for(auto j : v) {
      int l = i-j.ff;
      int r = i-j.ss-1;
      l = max(0, l);
      r = max(0, r);
      tmp = ((tmp + pre[l]) % MOD - pre[r])%MOD;
    }
    tmp = (tmp+MOD)%MOD;
    dp[i] = tmp;
    pre[i] = (pre[i-1] + dp[i]) % MOD;
  }
  vbug(dp);
  vbug(pre);
  cout << dp[n] << endl;
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
