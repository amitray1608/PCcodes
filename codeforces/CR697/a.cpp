#include <bits/stdc++.h>

using namespace std;

void solve() {
 long long n;
 cin >> n;
 while(n % 2 == 0) n >>= 1;
 cout << (n != 1 ? "YES" : "NO") << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite

