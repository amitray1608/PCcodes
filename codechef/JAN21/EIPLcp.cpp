#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t;
  cin >> t;
  while(t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
//    sort(a.rbegin(), a.rend());
    
    function<int()> simul = [&]() {
      int count = 0, A = 0, B = 0;
      for(int i = 0; i < n; i++) {
        if(~i&1) {
          A += a[i];
        } else {
          B += a[i];
        }
        if(A > k and B > k) {
          count = i;
          break;
        }
      }
      return count;
    };
    int res = simul();
    if(!res) cout << -1 << '\n';
    else cout << res << '\n';
  }
  return 0;
}
