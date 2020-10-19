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
  int n = (int) s.length();
  int ans = 1;
  for(int i = 1; i < n; i++) {
    int count = 1;
    while(s[i-1] == s[i])
      count++, i++;
    ans = max(ans, count);
  }
  cout << ans << endl;

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