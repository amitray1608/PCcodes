//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e5 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void solve(){
  ll n;
  cin >> n;
  ll a[n];
  ll sum = 0;
  ll freq[siz] = {0};
  for(ll &i : a) cin >> i, sum += i, freq[i]++;
  ll q;
  cin >> q;
  while(q--) {
    ll b, c;
    cin >> b >> c;
    ll minus = b*freq[b];
    sum -= minus;
    sum += freq[b]*c;
    freq[c] += freq[b];
    freq[b] = 0;
    cout << sum << endl;
  }

}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while(t--){
    //tt++;
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  