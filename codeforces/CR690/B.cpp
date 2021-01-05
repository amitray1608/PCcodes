#include<bits/stdc++.h>

using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  bool ok = false;
  if(s[0] == '2' and s[1] == '0' and s[n-1] == '0' and s[n-2] == '2')
    ok = true;
  if(s[0] == '2' and s[1] == '0' and s[2] == '2' and s[3] == '0')
        ok = true;
  if(s[n-1] == '0' and s[n-2] == '2' and s[n-3] == '0' and s[n-4] == '2') 
    ok = true;
  if(s[n-1] == '0' and s[n-2] == '2' and s[n-3] == '0' and s[0] == '2') 
    ok = true;
  if(s[0] == '2' and s[1] == '0' and s[2] == '2' and s[n - 1] == '0') 
    ok = true;
  cout << (ok ? "YES": "NO") << endl;
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
