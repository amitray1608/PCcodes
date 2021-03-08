
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  if (n % k) {
    cout << -1 << '\n';
    return;
  }
  vector<int> f(26, 0);
  for (char c : s) {
    f[c - 'a']++;
  }

  auto valid = [&]() {
    for (int i : f){
      if (i % k) return false;
    }
    return true;
  };

  for (int i = n - 1; i >= 0; i--) {
    int c = s[i];
    for (int j = 25; j >= 0; j--) {
      if (
    } 
  }
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


