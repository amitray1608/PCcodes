#include<bits/stdc++.h>
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
typedef long double dd;
const int MOD = 1e9 + 7;

void solve(){
  ll w, n;
  cin >> w >> n;
  vector<ll> a(w);
  for(ll &i : a) cin >> i;
  ll mini = LONG_MAX;
  for(int i  = 1; i <= n; i++) {
    ll sum = 0;
    for(int j = 0; j < w; j++) {
      sum += min({abs(i - a[j]), (a[j] + n - i), (n - a[j] + i)});
    }
    mini = min(mini, sum);
  }
  cout << mini << '\n';
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1, tt = 0;
  cin >> t;
  while(t--){
  cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
}//Hajimemashite
