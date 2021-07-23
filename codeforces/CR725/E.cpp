
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
    int ca = a;
    int cb = b;
    int counta = 0;
    int countb = 0;
    for (int i : primes) {
      while (ca % i == 0) {
        ca /= i;
        counta++;
      }
      while (cb % i == 0) {
        cb /= i;
        countb++;
      }
      if (i * i > b and i * i > a) break;
    }
    if (cb != 1) countb++; //ma[cb]++;
    if (ca != 1) counta++; //ma[ca]++;
    int gc = __gcd(a, b);
    bool ok = true;
    if ((a == 1 && b == 1) or (k & 1 and a == b)) ok = false;
    else if (k == 1 && !(gc == a or gc == b)) ok = false;
    else if (k > counta + countb) ok = false;
    cout << (ok ? "YES" : "NO") << '\n';
  }	
  return 0;
} //Hajimemashite



