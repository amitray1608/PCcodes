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
    long long sum = 0, count = 0;
    for(int i = 0; i < n; i++) {
      int x; cin >> x;
      a[i] = x;
      if(x % k == 0) count++;
      sum += x;
    }
    int m = 0, M = 0;
    if(sum % k == 0) m = sum / k;
    else m = sum / k + 1;
    sum = 0;
    for(int i = 0; i < n; i++) {
      if(a[i] % k == 0) sum += a[i]/k;
      else sum += a[i] / k + 1;
    }
    M = sum;
      cout << m << ' ' << M << '\n';
  }
  return 0;
}

