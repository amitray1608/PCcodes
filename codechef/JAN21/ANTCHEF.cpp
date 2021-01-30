#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &i : a) cin >> i;
    int pre[n] = {0};
    for(int i = 1; i < n; i++) {
      pre[i] = pre[i - 1] + 1;
    }
    pre[n - 1] = 0;
    for(int i = n - 2; i >= 1; i--) {
      pre[i] = min(pre[i], pre[i + 1] + 1);
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      cout << pre[i]+1 << '\n';
      ans += pre[i] * 2;
    } 
    cout << ans << '\n';
  }
  return 0;
}
