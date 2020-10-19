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
  ll n, k;
  cin >> n >> k;
  vector<int> a(n);
  for(int &i : a) cin >> i;
  int maxi = *max_element(a.begin(), a.end());
  for(int &i : a)
    i = maxi-i;
  k--;
  if(k&1) {
    maxi = (*max_element(a.begin(), a.end()));
    for(int &i : a)
      i = maxi-i;
  }
  for(int &i : a) cout << i << ' ';
  cout << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(10);
  int t = 1;
  cin >> t;
  for(int tt = 1; tt <= t; tt++) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  