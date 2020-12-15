#include<bits/stdc++.h>

using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;

void solve() {
  int n, m;
  cin >> n >> m;
  string s[n];
  for(string &i : s) cin >> i;
  
  vector<vector<int>> pre(n, vector<int> (m, 0));
  ll count = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(!j) pre[i][j] =  (s[i][j] == '*');
      else pre[i][j] = (s[i][j] == '*' ? pre[i][j - 1] + 1 : 0); 
    }
  }

//  for(int i = 0; i < n; i++) {
//    for(int j = 0; j < m; j++) cout << pre[i][j] << ' ';
//    cout << endl;
//  }
  
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(s[i][j] == '.') continue;
      for(int h = 0; h < min({n - i, m - j, j + 1}) ; h++) {
        int x = i + h;
        int yleft = j - h, yright = j + h;
        if(pre[x][yright] - (yleft - 1 < 0 ? 0 : pre[x][yleft - 1]) == 2 * h + 1) count++;
        else
          break;
      }
    }
  }

//  auto valid = [&](int x, int y) {
//    return (x + 1 < n and y - 1 >= 0 and y + 1 < m);
//  };
//
//  for(int i = n - 2; i >= 0; i--) {
//    for(int j = m - 1; j >= 0; j--) {
//      if(s[i][j] == '.') continue;
//      if(valid(i, j)) {
//        count += min({pre[i + 1][j - 1], pre[i + 1][j], pre[i + 1][j + 1]});
//        pre[i][j] += min({pre[i + 1][j - 1], pre[i + 1][j], pre[i + 1][j + 1]});
//      }
//    }
//  }

  cout << count << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1, tt = 0;
  cin >> t;
  while(t--){
    //cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite
