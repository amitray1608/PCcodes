#include<bits/stdc++.h>
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
typedef long double dd;
const int MOD = 1e9 + 7;

void solve(){
  int n, k;
  cin >> n >> k;
  vector<vector<int>> a(n, vector<int>(n, 0));
  int i = 0, j = 0, kk = k;
  while(k--) {
    a[i][j] = 1;
    i++, j++;
    j %= n; 
    if(i == n)
      i = 0, j++, j %= n;

    for(auto i : a) {
      for(auto j : i)
        cout << j;
      cout << endl;
    }
    cout << "___________________" << endl;
  }
  if(k == 0) cout << 0 << endl;
  cout << (kk % n == 0 ? 0 : 2) << endl;
  for(auto i : a) {
    for(auto j : i)
      cout << j;
    cout << endl;
  }
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
