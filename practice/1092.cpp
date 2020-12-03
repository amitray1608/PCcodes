#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;

void solve(){
  ll n;
  cin >> n;
  if(((n * (n + 1LL))/2LL) & 1LL) {
    cout << "NO";
  } else {
    vector<int> f, s;
    cout << "YES\n";
    int i = 1, j = (n&1 ? n - 1 : n), c = 1;
    for(int ii = 0; ii < n/2; ii++) {
      if(c&1)
        f.push_back(i++), f.push_back(j--);
      else
        s.push_back(i++), s.push_back(j--);
      c ^= 1;
    }
    if(n&1) {
      if(c&1)f.push_back(n);
      else
        s.push_back(n);
    }
    cout << f.size() << endl;
    for(int &i : f) cout << i << ' ';
    cout << endl;
    cout << s.size() << endl;
    for(int &i : s) cout << i << ' ';
    cout << endl;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1, tt = 0;
  //cin >> t;
  while(t--){
    //cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite
