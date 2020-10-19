#include<bits/stdc++.h>
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
typedef long double dd;
const int MOD = 1e9 + 7;

void solve(){
  ll n;
  cin >> n;
  set<ll> ans;
  ll i = 1;
  while(true) {
    if(i*i > n) break;
    if(n % i == 0) {
      ans.insert(i);
      ll x = n/i;
      ans.insert(x);
    }
    i++;
  }
  for(auto ii : ans) cout << ii << endl;
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
