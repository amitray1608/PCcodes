#include<bits/stdc++.h>

using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;
const int inf = 1e8;

int lis(vector<int> const& a) {
    int n = a.size();
    const int INF = 1e9;
    vector<int> d(n+1, INF);
    d[0] = -INF;

    for (int i = 0; i < n; i++) {
        int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[j-1] < a[i] && a[i] < d[j])
            d[j] = a[i];
//        for(int k = 0; k <= n; k++) cout << d[i] << ' ';
//        cout << endl;
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
      cout << d[i] << ' ';  
      if (d[i] < INF)
            ans = i;
    } cout << endl;
    return ans;
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
//  vector<int> dp(n + 1, inf);
//  dp[0] = -inf;
//  for(int i = 0; i < n; i++) {
//    int j = upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
//    if(dp[j-1] < a[i] and a[i] < dp[j])
//      dp[j] = a[i];
//    for(j = 0; j <= n; j++) cout << dp[i] << ' ' ;
//    cout << endl;
//  }
  int ans = lis(a);
  cout << ans << '\n';
}

int main(){
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
