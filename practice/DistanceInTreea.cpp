#include<bits/stdc++.h>
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
typedef long double dd;
const int MOD = 1e9 + 7;

const int MAXN = 50005;

int n, k, ans;
vector<vector<int>> adj(MAXN), dp(MAXN);

template<typename T>
string to_string(vector<T> v) {
  string res;
  for(auto &i : v)
    res += char('0'+i), res += ", ";
  res.pop_back(), res.pop_back();
  return res;
}
 
template<class A> void vbug(A x) {
  cout << '[' << to_string(x) << ']' << endl;
}

void dfs(int u, int p = -1) {
  vector<int> d(k);
  d[0] = 1;
  deb(u);
  for(auto ii : adj[u]) if(ii != p) {
    dfs(ii, u);
    for(int i = 0; i < k; i++) {
      ans += d[i] * dp[ii][k - i - 1];
    }
    for(int i = 0; i < k - 1; i++) {
      d[i+1] += dp[ii][i];
    }
  }
  deb(u);
  vbug(d);
  dp[u] = d;
}

void solve(){
  cin >> n >> k;
  for(int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  ans = 0;
  dfs(0);
  cout << ans << endl;
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
}
