#include<bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  long long maxi = 0, maxii = 0, ans;
  for(int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    if(x >= maxi) {
      maxii = maxi;
      maxi = x;
    } else if(x > maxii) {
      maxii = x;
    }
  }
  ans = maxi * maxii;
  cout << ans << endl;
  return 0;
}
