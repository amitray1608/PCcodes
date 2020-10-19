#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef double dd;
const ll MOD = 1e9 + 7;

void solve(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& i : a) cin >> i;
  sort(all(a));
  const ll inf = 1e18;
  ll ans = -inf;
  for (int k = 0; k <= 5; k++) {
    int t = 5 - k;
    ll cur = 1;
    for (int i = 0; i < k; i++)
      cur *= a[i];
    for (int i = 0; i < t; i++)
      cur *= a[n - i - 1];
    ans = max(ans, cur);
  }
  cout << ans << '\n';
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
