//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
ll MOD = 1000000000;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void solve(){
  int n;
  cin >> n;
  vector<int> a(n);
  int otv = 0, mx = -1, mn = 1000000001;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i) {
      if (a[i] == -1 && a[i - 1] != -1) {
          mx = max(mx, a[i - 1]);
          mn = min(mn, a[i - 1]);
      }
      if (a[i - 1] == -1 && a[i] != -1) {
          mx = max(mx, a[i]);
          mn = min(mn, a[i]);
      }
      if (a[i] != -1 && a[i - 1] != -1) {
          otv = max(otv, abs(a[i] - a[i - 1]));
      }
    }
  }
  if (mx == -1) {
      cout << otv << " " << 0 << "\n";
  } else {
      int k = (mx + mn) / 2;
      otv = max(otv, abs(mx - k));
      otv = max(otv, abs(k - mn));
      cout << otv << " " << k << "\n";
  }

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