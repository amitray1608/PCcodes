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
    long long sum = 0;
    vector<int> a(n);
    for(int &i : a) cin >> i;
    for(int i = 0; i < n; i++) {
      int count = 1;
      if(a[i] % k == 0) {
        while(a[i] % k == 0) {
          count++;
          sum += count *(k * (a[i]/k));
          a[i] /= k;
        }
      } else break;
    }
    cout << sum << '\n';
  }
  return 0;
}
