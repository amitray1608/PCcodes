
#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 1;

vector<int>is_prime;
void seive(int n) {
  is_prime.assign(n+1, 0);
  for (int i = 2; i <= n; i++) {
    for (int j = i; j <= n; j += i)
      if (!is_prime[j])
        is_prime[j] = i;
  }
}

void solve() {
  int n;
  cin >> n;
  vector<int> mp(maxn), mc(maxn);
  for (int i = 0; i < n; i++) {
    int u, v;
    cin >> u >> v;
    mp[u] = v;
    mc[u] = v;
  }
  
  auto check = [&](int x) {
    bool is = true;
    int xcp = x;
    while (x > 1) {
      if (mp[is_prime[x]] == 0) {
        is = false;
        break;
      }
      mp[is_prime[x]]--;
      x /= is_prime[x];
    }
    int res = 0;
    int i = 0, half = 500;
    while (i < half) {
      res += i * mp[i];
      mp[i] = mc[i];
      i++;
    }
    if (is and res == xcp) return true;
    return false;
  };
  int maxi = 1e4;
  for (int i = maxi; i >= 2; i--) {
    if (check(i)) {
      cout << i << '\n';
      return;
    }
  }
  cout << 0 << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int t = 1;
  cin >> t;
  seive(5e4 + 3);
  for (int tt = 1; tt <= t; ++tt) {
    cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite


