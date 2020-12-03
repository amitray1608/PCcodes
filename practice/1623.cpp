#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;
ll sum = 0, n;
vector<int> a;
ll recc(int i, ll curr) {
  if(i == n) {
    return abs((sum - curr) - curr);
  }
  return min(recc(i + 1, curr + a[i]), recc(i + 1, curr));
}

void solve(){
  cin >> n;
  a.resize(n);
  for(int &i : a) cin >> i;
  sum = accumulate(a.begin(), a.end(), 0LL);
  ll ans = recc(0, 0LL);
  cout << ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1, tt = 0;
  //cin >> t;
  while(t--){
    //cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite
