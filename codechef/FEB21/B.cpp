#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e6 + 3;

vector<int>is_prime(maxn + 1, true);
vector<int> cum(maxn + 1, 0);
void seive() {
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i <= maxn; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j <= maxn; j += i)
        is_prime[j] = false;
    }
  }
}

void solve() {
  int x, y;
  cin >> x >> y;
  bool ok = (cum[x] >= y);
  cout << (ok ? "Divyam" : "Chef") << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
  cin >> t;
  seive();
  for (int i = 2; i <= maxn; i++) {
    if (is_prime[i]) {
      cum[i] = cum[i - 1] + 1;
    } else {
      cum[i] = cum[i - 1];
    }
  }
  for (int tt = 1; tt <= t; ++tt) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite


