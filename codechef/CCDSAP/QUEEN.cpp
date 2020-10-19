//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

int dx[] = {0, -1, -1, -1,  0,  1,  1, 1};
int dy[] = {1,  1,  0,  -1, -1, -1, 0, 1};

vector<string>v;
int n, m;
bool check(int u, int vv) {
  if(u > -1 and u < n and vv > -1 and vv < m and v[u][vv] != 'X')
    return true;
  return false;
}

void solve(){
  cin >> n >> m;
  v.resize(n);
  int x, y, X, Y;
  for(int i = 0; i < n; i++){
    cin >> v[i];
    for(int j = 0; j < m; j++){
      if(v[i][j] == 'S')
        x = i, y = j;
      if(v[i][j] == 'F')
        X = i, Y = j;
    }
  }
  queue<pair<int, int>>q;
  q.push({x, y});
  int dist[n][m];
  memset(dist, 0, sizeof dist);
  dist[x][y] = 1;
  while(!q.empty()) {
    auto f = q.front();
    q.pop();
    x = f.first, y = f.second;
    // cout << "##" << x << ' ' << y << endl;
    for(int i = 0; i < 8; i++) {
      int u, vv;
      u = x+dx[i], vv = y+dy[i];
      while(check(u, vv)){
        if(dist[u][vv] == 0){
          dist[u][vv] = dist[x][y]+1;
          q.push({u, vv});
        } else if(dist[u][vv] != dist[x][y]+1)
            break;
        u += dx[i];
        vv += dy[i];
      }
    }
  }
  
  cout << (dist[X][Y]-1) << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while(t--){
    //tt++;
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  