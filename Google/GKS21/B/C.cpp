
//Sleepy as Hell.
#include <bits/stdc++.h>

using namespace std;
#define int int64_t

vector <int> primes;
void sieve(){
  const int n = 10000000;
  vector<bool> prime(n + 1, true);
  for (int p = 2 ; p * p <= n; ++p) {
    if (prime[p] == true) {
      for (int i = p * 2 ; i <= n ; i += p)
        prime[i] = false;
    }
  }
  for (int p = 2 ; p <= n ; p++)
   if (prime[p])
    primes.push_back(p);
}

void solve() {
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 1; i < (int)primes.size(); i++) {
    int x = primes[i] * primes[i - 1];
    if (x <= n) {
      ans = x;
    }
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;
  sieve();
  for (int tt = 1; tt <= t; ++tt) {
    cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite


