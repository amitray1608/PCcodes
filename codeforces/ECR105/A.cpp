
#include <bits/stdc++.h>

using namespace std;
string s;

bool check(int a, int b, int cc) {
  int score = 0;
  for (char c : s) {
    if (c == 'A') score += a;
    else if (c == 'B') score += b;
    else score += cc;
    if (score < 0) return false;
  }
  return (score == 0);
}

void solve() {
  cin >> s;
  bool ok = false;
  int a = 0, b = 0, c = 0;
  int n = (int)s.size();
  for (int i = 0; i < n; i++) {
    if (s[i] == 'A') a++;
    else if (s[i] == 'B') b++;
    else c++;
  }
  int A = 0, B = 0, C = 0;
  if (s[0] == 'A') A = 1;
  else if (s[0] == 'B') B = 1;
  else C = 1;
  int x[] = {1, -1};
  if (A) {
    for (int i : x)
      for (int j : x)
        ok |= check(1, i, j);
  } else if (B) {
    for (int i : x)
      for (int j : x)
        ok |= check(i, 1, j);
  } else {
    for (int i : x)
      for (int j : x)
        ok |= check(i, j, 1);
  }
  cout << (ok ? "YES" : "NO") << '\n';
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


