#include <bits/stdc++.h>

using namespace std;
int n;
vector<int> res, a;

void DandC(int l, int r, int dep = 0) {
  if (l > r) return;
  int maxi = 0, pos = 0;
  for (int i = l; i <= r; i++) {
    if (a[i] > maxi) {
      maxi = a[i];
      pos =  i;
    }
  }
  res[pos] = dep;
  DandC(l, pos - 1,  dep + 1);
  DandC(pos + 1, r, dep + 1);
}

void solve() {
  cin >> n;
  res.resize(n, 0);
  a.resize(n, 0);
  for (int &i : a) cin >> i;
  DandC(0, n - 1);
  for (int i : res) 
    cout << i << ' ';
  cout << '\n';
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


