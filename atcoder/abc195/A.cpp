
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
 
  int m, h;
  cin >> m >> h;
  bool ok = (h % m == 0);
  cout << (ok ? "Yes" : "No") << '\n';

  return 0;
} //Hajimemashite


