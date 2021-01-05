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
  vector<ll> a(n + 1);
  for(int i = 1; i < n + 1; i++) cin >> a[i];
  for(int i = n; i > 0; i--) {
    ll j = i + a[i];
    if(j <= n) {
      a[i] += a[j];
    }
  }
  ll maxi = 0;
  for (int i = 1; i < n + 1; i++) {
    maxi = max(maxi, a[i]);
  }
  cout << maxi << '\n';
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
