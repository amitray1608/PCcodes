
#include<bits/stdc++.h>

using namespace std;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int a, b, c;
    cin >> a >> b >> c;
    int g = stoi(string(c, '1'));
    int x = g * pow(10, a - c);
    int y = g * pow(10, b - c);
    if (a >= b)
      x += g;
    else 
      y += g;
    cout << x << ' ' << y << '\n';
  }
  return 0;
} //Hajimemashite

