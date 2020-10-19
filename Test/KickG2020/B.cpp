#include<bits/stdc++.h>
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
typedef long double dd;
const int MOD = 1e9 + 7;

void solve(){
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  vector<vector<int>> left(n, vector<int>(n));
  for(auto &i : a) 
    for(auto &j : i) cin >> j;
  int maxi = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++)
      if(i == 0 or j == 0)
        left[i][j] = a[i][j];
      else
        left[i][j] = left[i - 1][j - 1] + a[i][j];
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) 
      maxi = max(maxi, left[i][j]);
  }
  cout << maxi << '\n';
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1, tt = 0;
  cin >> t;
  while(t--){
  cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
}//Hajimemashite
