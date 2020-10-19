#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef double dd;
const int MOD = 1e9 + 7;

int dx[]={1, 1, 0, -1, -1, -1, 0, 1};int dy[]={0, 1, 1, 1, 0, -1, -1, -1};//8 direction

void solve(){
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m)), vis(n, vector<int>(m, 0));
  for(auto &i : a)
    for(auto &j : i) cin >> j;
  int maxi = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(a[i][j] and !vis[i][j]) {
        queue<pair<int, int>>q;
        q.push({i, j});
        vis[i][j] = true;
        int count = 1;
        while(!q.empty()) {
          auto x = q.front();
          q.pop();
          int u = x.first, v = x.second;
          vis[u][v] = true;
          for(int k = 0; k < 8; k++) {
            int uu = u + dx[k], vv = v + dy[k];
            if(uu >= 0 and uu < n and vv >= 0 and vv < m and !vis[uu][vv] and a[uu][vv]) {
              count++;
              q.push({uu, vv});
              vis[uu][vv] = true;
              //cout << uu << ' ' << vv << endl;
            }
          }
        }
        maxi = max(maxi, count);
      }
    }
  }
  cout << maxi << endl;
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
