//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void solve() {
  int n, m, x, y;    
  cin >> n >> m >> x >> y;
  int vis[n+1][m+1] = {0};
  vis[x][y] = 1; 
  cout << x << " " << y << endl;
  int curr = x-1;    
  while(curr >= 1)    
    cout << curr << " " << y << endl, vis[curr--][y] = 1;
  curr = y-1;    
  while(curr >= 1)    
    cout << 1 << " " << curr << endl, vis[1][curr--] = 1;
  for(int i = 1; i <= n; i++){
    if(i&1){
      for(int j = 1; j <= m; j++){
        if(vis[i][j] == 0)    
          cout << i << " " << j << endl, vis[i][j] = 1;
      }
    }
    else{
      for(int j = m; j >= 1; j--){
        if(vis[i][j] == 0)    
          cout << i << " " << j << endl, vis[i][j] = 1;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(10);
  int t = 1;
  // cin >> t;
  for(int tt = 1; tt <= t; tt++) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  