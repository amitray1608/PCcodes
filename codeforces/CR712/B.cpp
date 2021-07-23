
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    vector<int> prea(n, 0), preb(n, 0);
    bool ok = false;
    for (int i = 0; i < n; i++) {
      prea[i] = (a[i] == '0' ? 1 : -1);
      preb[i] = (b[i] == '0' ? 1 : -1);
      if (i) {
        prea[i] += prea[i - 1];
        preb[i] += preb[i - 1];
      }
    }
    bool done = false;
    for (int i =  n - 1; i >= 0; i--) {
      if (!prea[i] and !preb[i]) {
        ok = true;
      }
      if ((!ok and prea[i] != preb[i]) or (abs(prea[i]) != abs(preb[i]))) {
        cout << "NO" << "\n";
        done = true;
        break;
      }
    }
    if (done) continue;
    cout << "YES" << '\n';
  }
  return 0;
} //Hajimemashite

