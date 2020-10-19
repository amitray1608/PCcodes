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
  int n;
  cin >> n;
  string s;
  cin >> s;
  string ans = "";
  int i  = n-1;
  for(; i >= 0; i--) {
    if((int)(s[i] - '0') % 2 != 0) {
      ans = ans + s[i]; 
      i--;
      break;
    }
  }
  for(; i >= 0; i--) {
    if(s[i] != '0') {
      if((int)(s[i]-'0') % 2 != 0 ) {
        ans += s[i];
        break;
      }
    }
  }
  reverse(ans.begin(), ans.end());
  if(ans.size() >= 2)
      cout << ans << endl;
  else
      cout << -1 << endl;
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