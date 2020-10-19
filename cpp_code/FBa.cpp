//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

const int INF = 10000000;

void solve(){
  int n;
  cin >> n;
  string I, O;
  vector<vector<char>>ans(n, vector<char>(n, 'N'));
  cin >> I >> O;
  for(int i = 0; i < n; i++) ans[i][i] = 'Y';

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(abs(i-j) == 1) 
        if(O[i] == 'Y' and I[j] == 'Y')
          ans[i][j] = 'Y';
    }
  }
    
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(i == j or ans[i][j] == 'Y') continue;
      if(abs(i-j) == 1) {
        if(O[i] == 'Y' and I[j] == 'Y')
          ans[i][j] = 'Y';
        continue;
      }
      for(int k = 0; k < n; k++) {
        if(ans[i][k] == 'Y' and ans[k][j] == 'Y')
             ans[i][j] = 'Y';
      }
    }
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++)
      cout << ans[i][j];
    cout << endl;
  }
  for(int i = 0; i < n; i++)
    ans[i].clear();
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  int t = 1, tt = 0;
  cin >> t;
  while(t--){
    tt++;
    cout << "Case #" << tt << ": " << endl;
    solve();
  }
  return 0;
}  
