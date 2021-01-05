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
  vector<ll> a(n);
  for(ll &i : a) cin >> i;
  sort(a.begin(), a.end());
  ll alice = 0, bob = 0, turn = 0;
  for(int i = n - 1; i >= 0; i--) {
    if(~a[i] & 1 and ~turn&1) alice += a[i];
    else if(turn&1 and a[i] & 1) bob += a[i];
    turn ^= 1;
  }
  if(alice == bob) {
    cout << "Tie" << '\n';
  } else if(alice > bob) {
    cout << "Alice"<< '\n';
  } else {
    cout << "Bob" << '\n';
  }
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
