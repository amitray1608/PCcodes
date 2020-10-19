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
  int n = (int)s.length();
  int a = 0, b = n, c = 0, d;
  for (int i = 0; i < (int)s.length(); i++) {
    if (s[i] == '1') a++;
  }
  d = n - a;
  for (int i = 1; i < (int)s.length(); i++) {
    if (s[i] == '1' && s[i-1] == '0') c++;
  }
  c += (s[n-1] == '0' && s[0] == '1');
  if(a*d > b*c) {
    cout << "SHOOT\n";
  } else if (a*d == b*c) {
    cout << "EQUAL\n";
  } else {
    cout << "ROTATE\n";
  }
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