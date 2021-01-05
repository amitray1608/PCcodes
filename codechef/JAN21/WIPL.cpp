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
    sort(a.rbegin(), a.rend());
    
    function<int()> simul = [&]() {
      long long A = a[0];
      long long B = a[1];
      int count = 2;
      for(int i = 2; i < n; i++) {
        if(A >= k and B >= k) break;
        if(A < B) A += a[i];
        else B += a[i];
        count++;
      }
      if(A < k or B < k) return -1;
      return count;
    };

    function<int()> simul2 = [&]() {
      long long A = a[0];
      long long B = 0;
      int count = 1;
      for(int i = 1; i < n; i++) {
        if(A >= k and B >= k) break;
        if(A < k) {
          while(i < n - 1 and A + a[i] >= k and B < k and ((A + a[i + 1]) >= k or (A + a[i] - k > k - A + a[i + 1]))) {
            B += a[i];
            count++;
            i++;
          }
          A += a[i];
        } else {
          while(i < n - 1 and B + a[i] >= k and A < k and ((B + a[i + 1]) >= k or (B + a[i] - k > k - B + a[i + 1]))) {
            A += a[i];
            count++;
            i++;
          }
          B += a[i];
        }
        count++;
      }
      if(A < k or B < k) return -1;
      return count;
    };

    if(n < 2) {
      cout << -1 << '\n';
      continue;
    }
    int res = simul();
    int ress = simul2();
    if(res != -1 and ress != -1) cout << min(res, ress) << '\n';
    else if(res == -1) cout << ress << '\n';
    else cout << res << '\n';
  }
  return 0;
}
