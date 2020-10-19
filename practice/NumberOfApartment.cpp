#include<bits/stdc++.h>
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
typedef long double dd;
const int MOD = 1e9 + 7;

void solve(){
  int n;
  cin >> n;
  for(int i = 0; i * 7 <= n; i++) {
    int sv = n - (i * 7);
    for(int j = 0; j * 5 <= n; j++) {
      int fv = sv - (j * 5);
      if(fv >= 0 and fv % 3 == 0) {
        cout << fv / 3 << ' ' << j << ' ' << i << endl;
        return;
      }
    }
  }
  cout << -1 << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1, tt = 0;
  cin >> t;
  while(t--){
  //cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
}//Hajimemashite
