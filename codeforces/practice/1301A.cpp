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
  string a, b, c;
  cin >> a >> b >> c;
  bool flag = true;
  for(int i = 0; i < (int)a.length(); i++) {
    if(a[i] == c[i] or b[i] == c[i]) continue;
    flag = false;
  }
  cout << (flag ? "YES" : "NO") << endl;
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