#include <bits/stdc++.h>

using namespace std;
#define int int64_t

const int maxn = 1e5 + 1;
vector<int>is_prime;
vector<int>primes;

void seive(int n) {
  is_prime.assign(n+1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i <= n; i++) {
      if (is_prime[i]) {
          for (int j = i * i; j <= n; j += i)
              is_prime[j] = false;
      }
  }
  for(int i = 2; i <= n; i++)
    if(is_prime[i]) primes.push_back(i);
}



void solve() {
  int d;
  cin >> d;
  int n = *lower_bound(primes.begin(), primes.end(), 1 + d);
  int nn = *lower_bound(primes.begin(), primes.end(), n + d);
  int ans = n * nn;
  cout << ans << '\n';
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
  cin >> t;
  seive(maxn);
  for (int tt = 1; tt <= t; ++tt) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite

