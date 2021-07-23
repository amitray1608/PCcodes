
#include <bits/stdc++.h>

using namespace std;

class DSU {
  public:
  int n;
  vector<int> p, w;
  DSU(int nn) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
    w.resize(n, 1);
  }

};

void solve() {
  int n, m;
  cin >> n >> m;

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


