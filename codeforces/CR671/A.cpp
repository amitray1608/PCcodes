#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef double dd;
const int MOD = 1e9 + 7;

void solve(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  s = "$" + s;
  int odde(0), oddo(0), evene(0), eveno(0);
  for (int i = 1; i <= n; i++) {
    if(i&1) {
      (s[i] - '0') & 1 ? oddo++ : odde++;
    } else {
      (s[i] - '0') & 1 ? eveno++ : evene++;
    }
  }
  bool ans = 0;
  if(oddo > eveno) ans = 1;

}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1, tt = 0;
  cin >> t;
  while(t--){
    //tt++;
    //cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
