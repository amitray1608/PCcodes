#include<bits/stdc++.h>

using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m, 0));
  int mini = INT_MAX;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> a[i][j];
      mini = min(mini, a[i][j]);
    }
  }
  ll ans = 0;
  for(int i = 0; i < n; i++) 
    for(int j = 0; j < m; j++) 
      ans += a[i][j] - mini;
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
