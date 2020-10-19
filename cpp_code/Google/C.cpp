#include<bits/stdc++.h>
#define endl '\n'
#define ff first
#define ss second
#define deb(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
typedef long double dd;
const int MOD = 1e9 + 7;

void solve(){
  int s, r, p, R, P, c;
  cin >> s >> r >> p >> R >> P >> c;
  int m[4][4] = {0}, ans;
  vector<pair<int, int>> a(c);
  for(int i = 0; i < c; i++) {
    cin >> a[i].ff >> a[i].ss;
    m[a[i].ff][a[i].ss] = -1;
  }
  if(m[2][2] == -1 or c == 2) {
    cout << 0 << endl;
  } else if(r == 1 and p == 1) {
      if(R == 2 and P == 2)
        cout << -(2 - c) << endl;
      else
        cout << 2 - c << endl;
  } else if(r == 2 and p == 2) {
      cout << 2 - c << endl;
  } else if(r == 2 and p == 1) {
      if(R == 2 and P == 2)
        cout << -(2 - c) << endl;
     else
       cout << 2 - c << endl;
  } else if(r == 2 and p == 3) {
    if(R == 2 and P == 2)
      cout << -(2 - c) << endl;
    else
      cout << 2 - c << endl;
  } else 
      cout << 0 << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1, tt = 0;
  cin >> t;
  while(t--){
    cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
}
