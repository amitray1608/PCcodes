
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    for (int i = 1; i < 1001; i++) {
      int x = i * i;
      cout << x << endl;
      int inp;
      cin >> inp;
      if (inp == 1) break;
    }
  }
  return 0;
} //Hajimemashite

