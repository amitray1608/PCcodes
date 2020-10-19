//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void solve(){
  int h, w, k;
  cin >> h >> w >> k;
  vector<string> ar(h);
  int res = 0;
  for(auto &x: ar) cin >> x;
  for(int mask1 = 0; mask1 < (1 << h); ++mask1) {
    for(int mask2 = 0; mask2 < (1 << w); ++mask2) {
      int here = 0;
      for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
          if((mask1 & (1 << i)) || (mask2 & (1 << j))) continue;
          if(ar[i][j] == '#') here++;
        }
      }
      res += int(here == k);
    }
  }
  cout << res << '\n';
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while(t--){
    //tt++;
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  