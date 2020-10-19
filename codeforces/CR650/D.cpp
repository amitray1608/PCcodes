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
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<int> count(26);
  for (char c: s)
      count[c-'a']++;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
      if (k % i != 0) 
          continue;
      for (int c = 1; c <= n / i; c++) {
          int r = 0;
          for (int x = 0; x < 26; x++)
              r += count[x] / c;
          if (r >= i)
              ans = max(ans, c * i);
      }
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