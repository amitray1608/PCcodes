
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int a, b;
  cin >> a >> b;
  int sum = a + b;
  if(sum >= 15 && b >= 8)
    cout << 1 << '\n';
  else if(sum >= 10 && b >= 3) 
    cout << 2 << '\n';
  else if(sum >= 3)
    cout << 3 << '\n';
  else
    cout << 4 << '\n';
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


