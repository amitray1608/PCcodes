#include<bits/stdc++.h>

using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;

void solve() {
  ll n, m, k;
  cin >> n >> m >> k;
  if(n * m < k) {
    cout << "No" << '\n';
    return;
  } 
  if(k % m == 0 or k % n == 0 or k&1) cout << "Yes\n";
  else cout << "No" << '\n';
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
