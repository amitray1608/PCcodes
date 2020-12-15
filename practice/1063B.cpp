#include<bits/stdc++.h>

using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;

int dx[] = {1, 0, -1, 0}; int dy[] = {0, 1, 0, -1}; //4 Direction

void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  int X, y, l, r;
  cin >> X >> y >> l >> r;
  for(int i = 0; i < n; i++) cin >> a[i];
  X--, y--;
  vector<vector<bool>> vis(n, vector<bool>(m, false));
  deque<array<int, 4>> q;
  q.push_back({X, y, l, r});
  vis[X][y] = 1;
  int count = 0;
  while(!q.empty()) {
    auto x = q.front(); q.pop_front();
    int u = x[0], v = x[1], L = x[2], R = x[3];
  //    cout << u << ' ' << v << endl;
    count++;
    for(int i = 0; i < 4; i++) {
      int U = u + dx[i], V = v + dy[i], LL = 0, RR = 0;
      if(U >= 0 and U < n and V >= 0 and V < m) {
        if(!vis[U][V] and a[U][V] == '.') {
          if(i == 1) {
            if(R) RR++;
            else continue;
          } 
          if(i == 3) {
            if(L) LL++;
            else continue;
          }
          if(i == 0 or i == 2) {
            q.push_front({U, V, L, R});
          } else {
            q.push_back({U, V, L-LL, R-RR});
          }
          vis[U][V] = true;
        }
      }
    }
  }
//  for(int i = 0; i < n; i++) {
//    for(int j = 0; j < m; j++) cout << vis[i][j] << ' ';
//    cout << endl;
//  }
  cout << count << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1, tt = 0;
  //cin >> t;
  while(t--){
    //cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite
