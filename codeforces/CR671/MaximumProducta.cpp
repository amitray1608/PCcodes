#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef double dd;
const ll MOD = 1e9 + 7;

void solve(){
  ll n;
  cin >> n;
  vector<ll>pos, neg;
  for (ll i = 0; i < n; i++) {
    ll x;
    cin >> x;
    x >= 0 ? pos.push_back(x) : neg.push_back(x);
  }
  sort(all(pos), greater<ll>());
  sort(all(neg));
  ll prev = 1, maxi = -(1e18);
  for(ll i = 0; i < min(5LL, (ll)pos.size()); i++) {
    prev *= pos[i]; 
    ll x = prev, count = i+1;
    for(ll j = 0; j < min(5LL, (ll)neg.size()) and count < 5; j++) {
      x *= neg[j];
      count++;
    }
    if(count == 5)
      maxi = max(maxi, x);
  } 
  prev = 1; ll maxi2 = -(1e18);
  for(ll i = 0; i < min(5LL, (ll)neg.size()); i++) {
    prev *= neg[i]; 
    ll x = prev, count = i+1;
    for(ll j = 0; j < min(5LL, (ll)pos.size()) and count < 5; j++) {
      x *= pos[j];
      count++;
    }
    if(count == 5)
      maxi2 = max(maxi2, x);
  } 
  cout << max(maxi, maxi2) << endl;
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
