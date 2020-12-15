#include<bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while(t--) {
    long long n, sum = 0;
    cin >> n;
    long long ans = 0;
    while(sum < n) {
      ans++;
      sum += ans * ans;
    }
    cout << ans << endl;
  }
  return 0;
}
