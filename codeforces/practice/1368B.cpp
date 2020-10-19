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
    ll k;
    cin >> k;
    string s = "codeforces";
    int n = 10;
    std::vector<int> v(n, 1);
    if(k == 1){
      cout << s << endl;
      return;
    }
    ll ii = 0, p = 1;
    while(p < k) {
      p /= v[ii];
      v[ii]++;
      p *= v[ii];
      ii++;
      ii = (ii%10);
    }
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < v[i]; j++) {
        cout << s[i];
      }
    }
    cout << endl;
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