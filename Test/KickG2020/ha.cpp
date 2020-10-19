#include<bits/stdc++.h>
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
typedef long double dd;
const int MOD = 1e9 + 7;

void solve(){
  int n, a, b;
  cin >> n >> a >> b;
  ll sol = LONG_MAX;
  for(int i = 0; i < n; i++) {
    ll curr = ((i * i) * a) + ((n - i) * (n - i) * b);
    sol = min(sol, curr);
  }
  cout << sol << endl; 
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1, tt = 0;
  cin >> t;
  while(t--){
  //cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
}//Hajimemashite
