#include<bits/stdc++.h>
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
typedef long double dd;
const int MOD = 1e9 + 7;

int dx[]={1, 0, -1, 0};int dy[]={0, 1, 0, -1}; //4 Direction


void solve(){
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  bool vis[n][m];
  bool flag = false;
  memset(vis, 0, sizeof vis);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(a[i][j] == '*') {
        int count = 0;
        for(int k = 0; k < 4; k++) {
          int x = i + dx[k], y = j + dy[k];
          if(x >= 0 and x < n and y >= 0 and y < m) {
            if(a[x][y] == '*') count++;
          }
          if(count == 4) {
            int u = i, d = i, l = j, r = j;
            while(u >= 0 and a[u][j] == '*') vis[u--][j] = true;
            while(d < n and a[d][j] == '*') vis[d++][j] = true;
            while(l >= 0 and a[i][l] == '*') vis[i][l--] = true;
            while(r < m and a[i][r] == '*') vis[i][r++] = true;
            for(int ii = 0; ii < n; ii++) {
              for(int jj = 0; jj < m; jj++)
                if(vis[ii][jj] != (a[ii][jj] == '*')) {
                  cout << "NO" << endl;
                  return;
                }
            }
              cout << "YES" << endl;
              return;
          }
        }
      }
    }
  }
  cout << "NO" << endl;
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
}//Hajimemashite
