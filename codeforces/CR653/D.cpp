//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void solve(){
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  map<ll, ll>check;
  for(ll &i : a){
    cin >> i;
    if(i%k)
      check[k - i%k]++;
  } 
  if(check.empty()){
    cout << 0 << endl;
    return;
  }
  ll count = 0;
  for(auto i : check) {
    cout << i.first << ' ' << i.second << endl;
    count = max(count, i.first+(i.second-1)*k);
  }
  cout << count+1 << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while(t--){
    //tt++;
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  