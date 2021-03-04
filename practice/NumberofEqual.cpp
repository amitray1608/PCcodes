
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for (int &i : a) cin >> i;
  for (int &i : b) cin >> i;
  vector<int> c(m, 0);
  int i = 0, j = 0;
  long long count = 0, ina = 0, inb = 0;
  while (i < n and j < m) {
    int curr;
    if (a[i] <= b[j]) curr = a[i];
    else curr = b[j];
    ina =  inb = 0;
    while (a[i] == curr) ina++, i++;
    while (b[j] == curr) inb++, j++;
    count += ina * inb;
  }
  cout << count << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
  //cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite


