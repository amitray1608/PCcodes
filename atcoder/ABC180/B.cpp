#include<bits/stdc++.h>
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
typedef long double dd;
const int MOD = 1e9 + 7;

void solve(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(int &i : a) cin >> i;
  ll m = 0, e = 0, c = 0, x = 0;
  for(int i = 0; i  < n; i++) {
    x = abs(a[i]);
    m += abs(x);
    e += (x * x);
    c = max(c, x);
  }
  cout << m << endl;
  cout << setprecision(20) << sqrt(e) << '\n';
  cout << c << '\n';
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1, tt = 0;
  //cin >> t;
  while(t--){
  //cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
}//Hajimemashite
