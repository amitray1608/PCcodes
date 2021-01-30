#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) {
    long long n, k, x;
    cin >> n >> k;
    x = k;
    while(x < n) x += k;
    long long ans = x / n;
    if(x % n == 0) cout << ans << '\n';
    else cout << ans + 1<< '\n';
  }
  return 0;
} 
