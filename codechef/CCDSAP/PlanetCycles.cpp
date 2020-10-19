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
  int n, q;
  cin >> n >> q;
  vector<int>a(n);
  for(int &i : a) cin >> i, i--;
  for(int i = 0; i < q; i++) {
    int x, k;
    cin >> x >> k;
    x--;
    int count = 1, ans = a[x];
    for(int j = a[x]; count < k; j = a[j]) {
      count++;
      if(count == k) {
        ans = a[j];
        break;
      }
    }
  cout << ans+1 << endl;
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