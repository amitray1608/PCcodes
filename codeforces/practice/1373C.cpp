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
  string s;
  cin >> s;
  int n = (int)s.size();
  intnt res = 0;
  // for(int ii = 0; ii < 100000; ii++) {
    int cur = 0;
    // bool flag = true;
    for(int i = 0; i < n; i++) {
      res++;
      if(s[i] == '+')
        cur = cur +1;
      else
        cur = cur-1;
      // cout << cur << ' ';
        if(cur < 0){
          cur = 0;
          res += i+1;
        }
      }
    // if(flag)
    //   break;
  // }
  cout << res << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while(t--){
    // tt++;
    // cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  