
#include<bits/stdc++.h>

using namespace std;
#define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int k, a, b;
  cin >> k >> a >> b;
  int res = 0;
  if (a == 0 or b == 0) {
    res = abs(a) / k + abs(b) / k;
    res++;
  } else if ((a < 0 and b < 0) or (a > 0 and b > 0)) {
    a = abs(a);
    b = abs(b);
    if (a > b) swap(b, a);
    res = abs(b / k - (a - 1) / k); 
  } else {
    res = b / k;
    res += abs(a / k) + 1;
  }
  cout << abs(res) << '\n';
  return 0;
} //Hajimemashite
