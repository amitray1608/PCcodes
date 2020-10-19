//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const ll siz = 1e6 + 5;
const ll MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for(ll &i : a) cin >> i;
  sort(a.begin(), a.end());
  ll mini = 0;
  for(ll i : a) {
    mini += i;
    mini--;
  }
  deb(mini);
  for(int x = 2;  x < 10; x++) {
      ll curr = 0; 
      for(ll i = 0; i < n; i++) {
        curr += abs(a[i]-pow(x, i));
        if(curr > mini) break;
      }
      deb(curr);
      mini = min(mini, curr);
  }
  cout << mini;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(10);
  ll t = 1;
  // cin >> t;
  for(ll tt = 1; tt <= t; tt++) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  