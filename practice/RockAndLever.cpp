#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef double dd;
const int MOD = 1e9 + 7;

void solve(){
  int n;
  cin >> n;
  int fre[32] = {0};
  ll ans = 0;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    int msb = __builtin_clz(x);//log2(x);
    ans += fre[msb];
    fre[msb]++;
  }
  cout << ans << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1, tt = 0;
  cin >> t;
  while(t--){
  //cout << "Case #" << ++t << ": ";
    solve();
  }
  return 0;
}
