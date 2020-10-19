#include<bits/stdc++.h>
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
typedef long double dd;
const ll MOD = 1e9 + 7;

void solve(){
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n), lenpre(m, 0);
  for(ll &i : a) cin >> i;
  vector<pair<ll, ll>> lv(m);
  ll j = 0;
  for(auto &i : lv) { 
    cin >> i.first >> i.second;
    if(j == 0) lenpre[j++] = i.first;
    else lenpre[j++] += i.first;
  }
  ll mini = INT_MIN;
  
  do {
    ll l = 0, h = 1e9;
    while(l <= h) {
      ll mid = l + (h - l) / 2;
      for(ll i = 0; i < m; i++) {
        ll len = lenpre[i].first, weg = lv[i].second; 
        ll dissum = 0;
        for(ll ii = 0; ii < n; ii++) {
          if(dissum < 
        }
      }
    }
  } while(next_permutation(a.begin(), a.end());
  
  cout << mini << '\n';
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  ll t = 1, tt = 0;
  //cin >> t;
  while(t--){
  //cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
}//Hajimemashite
