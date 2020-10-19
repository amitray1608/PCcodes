//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction


void solve() {
  int n, m, k;
  cin >>  n >> m >> k;
  set<pair<int, int>> mp;
  for(int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    mp.insert({x, y});
  }
  int ans = k*4;
  for(auto i : mp) {
    int x = i.first, y = i.second;
    for(int j = 0; j < 4; j++) {
      int X = x + dx[j], Y = y + dy[j];
      if(mp.find({X, Y}) != mp.end()) ans--;
    }
  }
  cout << ans << endl;
  mp.clear();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(10);
  int t = 1;
  cin >> t;
  for(int tt = 1; tt <= t; tt++) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  
/*
1
4 4 9
1 4
2 1 
2 2
2 3
3 1
3 3
4 1
4 2
4 3
*/