
#include<bits/stdc++.h>

using namespace std;
#define int int64_t
const int maxn = 1e6 + 5;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;

  vector<int>is_prime;
  is_prime.assign(maxn + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i <= maxn; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j <= maxn; j += i)
        is_prime[j] = false;
    }
  }
  vector<int> primes;
  for (int i = 2; i < maxn + 1; i++)
    if (is_prime[i]) primes.push_back(i);

  for (int tt = 1; tt <= t; ++tt) {
    int a, b, k;
    cin >> a >> b >> k;
    map<int, int> ma, mb;
    int gc = __gcd(a, b);
    int ca = a / gc;
    int cb = b / gc;
    if (k == 1) {
      if (ca == 1 and cb > 1) {
        cout << "YES" << '\n';
        continue;
      }
      if (ca > 1 and cb == 1) {
        cout << "YES" << '\n';
        continue;
      }
      cout << "NO" << '\n';
      continue;
    }
    int counta = 0;
    int countb = 0;
    int countg = 0;
    int gg = gc;
    for (int i : primes) {
      while (gg % i == 0) {
        gg /= i;
        countg++;
      }
      while (ca % i == 0) {
        ca /= i;
        counta++;
      }
      while (cb % i == 0) {
        cb /= i;
        countb++;
      }
      if (i * i > a / gc and i * i > b / gc and i * i > gc) break;
    }
    if (cb != 1) countb++; 
    if (gg != 1) countg++; 
    if (ca != 1) counta++;
    bool ok = true;
    if (k > counta + countb +  2 * countg) ok = false;
    cout << (ok ? "YES" : "NO") << '\n';
  }	
  return 0;
} //Hajimemashite


