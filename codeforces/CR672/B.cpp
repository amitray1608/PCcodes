#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef double dd;
const int MOD = 1e9 + 7;

void solve(){
  ll n;
  cin >> n;
  ll a[n];
  for(ll i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<vector<int>>pre(32, vector<int> (n, 0)), x;
  for(int i = 0; i < n; i++) {
    for(int ii = 0; ii < 32; ii++) {
      pre[ii][i] = a[i]%2;
      a[i] /= 2;
    }
  }
  x = pre;
  for(int i = 1; i < n; i++) {
    for(int ii = 0; ii < 32; ii++) {
      pre[ii][i] += pre[ii][i-1];
    } 
  }
  int ans = 0;
  for(int i = 1; i < n; i++) {
    int xx = 0;
    for(int ii = 0; ii < 32; ii++) {
      if(x[ii][i] and pre[ii][i-1] -1 > 0)
      ans += pre[ii][i-1] - 1;
    } 
  }
  cout << ans << "\n";
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1, tt = 0;
  cin >> t;
  while(t--){
  //cout << "Case #" << ++t << ": ";
    solve();
  }
  return 0;
}
