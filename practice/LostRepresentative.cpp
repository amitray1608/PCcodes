#include<bits/stdc++.h>
using namespace std;
int dx[]={1,0,-1,0};int dy[]={0,1,0,-1};
int main(){
    // write your code
    int t;
    cin >> t;
    while(t--) {
      int n, p;
      cin >> n;
      vector<vector<int>> adj(n, vector<int>(n)), ans(n, vector<int>(n, 0));
      vector<vfector<int>> vis = ans;
      for(int i = 0; i < n; i++)
          for(int j = 0; j < n; j++)
              cin >> adj[i][j];
      cin >> p;
      for(int i = 0; i < n; i++) {
          for(int j = 0; j < n; j++) {
            if(!adj[i][j] or vis[i][j]) continue;
              queue<pair<int, int>> q;
              q.push({i, j});
              int count = 0;
              while(!q.empty()) {
                  auto qq = q.front();
                  q.pop();
                  int x = qq.first, y = qq.second;
//                  cout << x << ' ' << y << endl;
                  if(vis[x][y]) continue;
                  vis[x][y] = true;
                  count++;
                  for(int k = 0; k < 4; k++) {
                      int xx = x + dx[k];
                      int yy = y + dy[k];
                      if(xx < n and xx >= 0 and yy >= 0 and yy < n and !vis[xx][yy] and adj[xx][yy]) {
                          q.push({xx, yy});
                      }
                  }
              }
              ans[i][j] = count;
          }
      }
		  bool flag = false;
      for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
//          cout << ans[i][j] << ' ';
          if(ans[i][j] == p) {
            cout << i << ' ' << j << endl;
            flag = true;
              break;
          }
            if(flag) break;
        }//          cout << endl;
      }
     if(!flag)
        cout << -1 << ' ' << -1 << endl;
    }
    return 0;
}

