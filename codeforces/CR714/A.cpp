
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n, 0);
    if ((n - 1) / 2 < k) {
      cout << -1 << '\n';
      continue;
    }
    int x = n;
    for (int i = 0; i < k; i++) {
      a[2 * i + 1] = x--;
    }
    for (int i = 0; i < n; i++) {
      if (a[i] == 0) a[i] = x--;
    }
    for (int xx : a) cout << xx << ' ';
    cout << '\n';
  }
  return 0;
} //Hajimemashite

