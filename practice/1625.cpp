#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;

char given[] = {'R', 'L', 'D', 'U'};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

vector<vector<char>> s(7, vector<char>(7));
vector<vector<bool>> vis(7, vector<bool>(7, false));
int ans = 0, n = 7;

void recc(int x, int y) {
  if(x == 6 and y == 0) {
    ans++;
    return;
  }
  if(s[x][y] == '?') {
    for(int i = 0; i < 4; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if(xx >= 0 and xx < n and yy >= 0 and yy < n and !vis[xx][yy]) {
       vis[ 
        recc(xx, yy);
      }
    }
  } else {
    for(int i = 0; i < 4; i++) {
      if(given[i] == s[x][y]) {
        recc(x+dx[i], y+dy[i]);
      }
    }
  }
}

void solve(){
  int j = 0, k = 0;
  for (int i = 0; i < 48; i++) {
    cin >> s[j][k++];
    if(k == 7) {
      k = 0, j++;
      if(j == 6) k = 1;
    }
  }
  for(int i = 0; i < 7; i++) {
    for(j = 0; j < 7; j++) cout << s[i][j] << ' ';
    cout << endl;
  }
  recc(0, 0);
  cout << ans;
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
