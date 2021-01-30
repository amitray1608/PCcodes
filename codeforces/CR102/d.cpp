#include <bits/stdc++.h>
using namespace std;
void solution() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  s = '~' + s;
  vector<int> pref(n + 2), suf(n + 2), min_pref(n + 2, n + 1), max_pref(n + 2), min_suf(n + 2, n + 1), max_suf(n + 2);
  for (int i = 1; i <= n; i ++) {
    int delta = (s[i] == '-' ? -1: 1);
    pref[i] = pref[i - 1] + delta;
    min_pref[i] = min(pref[i], min_pref[i - 1]);
    max_pref[i] = max(pref[i], max_pref[i - 1]);
  }
  for (int i = n; i >= 1; i --) {
    min_suf[i] = min(min_suf[i + 1], pref[i]);
    max_suf[i] = max(max_suf[i + 1], pref[i]);
  }
  for (int x : min_pref) cout << x << " ";
  cout << endl;
  for (int x : max_pref) cout << x << " ";
  cout << endl;
  for (int x : min_suf) cout << x << " ";
  cout << endl;
  for (int x : max_suf) cout << x << " ";
  cout << endl;
  while (m --) {
    int l, r;
    cin >> l >> r;
    int low = 0, high = 0;
    if (l > 1) low = min(low, min_pref[l - 1]);
    if (l > 1) high = max(high, max_pref[l - 1]);
    if (r < n) low = min(low, pref[l - 1] - pref[r] + min_suf[r + 1]);
    if (r < n) high = max(high, pref[l - 1] - pref[r] + max_suf[r + 1]);
    cout << high - low + 1 << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0); 
  cin.tie(0);
  int tests;
  cin >> tests;
  for (int i = 1; i <= tests; i ++) solution();
}
