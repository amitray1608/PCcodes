
#include<bits/stdc++.h>

using namespace std;
#define int int64_t

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int a, aa;
    cin >> a >> aa;
    int b, bb;
    cin >> b >> bb;
    int f, ff;
    cin >> f >> ff;
    auto valid = [](int a, int b, int c) {
      return (c >= a and c <= b) or (c >= b and c <= a);
    };

    if ((a == b and b == f and valid(aa, bb, ff))) {
      cout << abs(aa - bb) + 2 << '\n'; 
    } else if ((aa == bb and bb == ff and valid(a, b, f))) {
      cout <<  abs (a - b) + 2 << '\n';
    }else {
      cout << abs(a - b) + abs(aa - bb) << '\n';
    }
  }	
  return 0;
} //Hajimemashite

