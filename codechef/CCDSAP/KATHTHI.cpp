//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;


int dx[] ={0, -1, 0, 1};
int dy[] ={1, 0, -1, 0};

void solve(){
  int n, m;
  cin >> n >> m;
  string s[n];
  for(int i = 0; i < n; i++) cin >> s[i];
  
  int dist[n][m];
  for(int i = 0; i < n; i++) 
    for(int j = 0; j < m; j++)
      dist[i][j] = INT_MAX;
  dist[0][0] = 0;
  deque<pair<int, int>>q;
  q.push_front({0, 0});
  while(!q.empty()){
    auto ii = q.front();
    q.pop_front();
    int u = ii.first, v = ii.second; 
    for(int i = 0; i < 4; i++){
      int x, y;
      x = u+dx[i], y = v+dy[i];
      if(x >= 0 and x < n and y >= 0 and y < m) {
        int w = (s[x][y] == s[u][v] ? 0 : 1);
        if(dist[x][y] > dist[u][v] + w) {
          dist[x][y] = dist[u][v] + w;
          if(w) {
            q.push_back({x, y});
          } else {
            q.push_front({x, y});
          }
        }
      }
    }
  }
  // for(int i = 0; i < n; i++) {
  //   for(int j = 0; j < m; j++)
  //     cout << dist[i][j] << ' ';
  //   cout << endl;
  // }
  cout << dist[n-1][m-1] << endl;
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

/*
4
2 2
aa
aa
2 3
abc
def
6 6
akaccc
aaacfc
amdfcc
aokhdd
zyxwdp
zyxwdd
5 5
abbbc
abacc
aaacc
aefci
cdgdd

*/