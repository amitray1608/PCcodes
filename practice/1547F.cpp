
#include<bits/stdc++.h>

using namespace std;
#define int int64_t

vector<int>is_prime, primes;
void seive(int n) {
  is_prime.assign(n+1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i <= n; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j <= n; j += i)
        is_prime[j] = false;
    }
  }
  for (int i = 0; i < n; i++) 
    if (is_prime[i]) primes.push_back(i);
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;
  seive(1e6);
  for (int tt = 1; tt <= t; ++tt) {
    int n;
    cin >> n;
    vector<int> a(n);
    int gc = 0, maxi = 0, res = 0;;
    for (int &i : a) cin >> i, gc = __gcd(gc, i);
    for (int &i : a) {
      i /= gc;
      maxi = max(i, maxi);
    }
    for (int j : primes) {
      if (j > maxi) break;
      bool ok = false;
      int count = 0;
      int mini = 0;
      for (int i = 0; i < 2 * n; i++) {
        int pos = i % n;
        if (!ok and a[pos] % j == 0) ok = true;
        if (ok) {
          count++;
          if (a[pos] % j) {
            mini = max(mini, count);
            count = 0;
            ok = false;
          }
        }
      }
      res = max(res, mini);
    }
    res = max((int)0, res - 1);
    cout << res << '\n';
  }
  return 0;
} //Hajimemashite

