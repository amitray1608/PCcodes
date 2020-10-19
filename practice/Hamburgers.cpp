//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void solve() {
  string s;
  cin >> s;
  ll rb = 0, rs = 0, rc = 0;
  for(char c : s) {
    (c == 'B' ? rb++ : (c == 'S' ? rs++ : rc++));
  }
  ll nb, ns, nc;
  cin >> nb >> ns >> nc;
  ll pb, ps, pc;
  cin >> pb >> ps >> pc;
  ll R;
  cin >> R;
  auto check = [&](ll x) {
    ll Rb = (x*rb), Rs = (x*rs), Rc = (x*rc);
    Rb = (Rb >= nb) ? Rb-nb : 0LL;  
    Rs = (Rs >= ns) ? Rs-ns : 0LL;  
    Rc = (Rc >= nc) ? Rc-nc : 0LL;  
    ll cost = (Rb * pb) + (Rs * ps) + (Rc * pc);
     return (cost <= R);
  };

  ll l = 0, r = 1e15;
  while(l <= r) {
    ll mid = l + (r-l)/2;

    if(check(mid))
      l = mid+1;
    else
      r = mid-1;
  }
  cout << r << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(10);
  int t = 1;
  // cin >> t;
  for(int tt = 1; tt <= t; tt++) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  
