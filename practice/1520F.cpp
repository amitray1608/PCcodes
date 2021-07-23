
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int n, t;
  cin >> n >> t;
  int k;
  cin >> k;
  auto check = [&](int x) {
    cout << "? " << 1 << ' ' << x << endl;
    int inp;
    cin >> inp;
    return (x - inp >= k);
  };
  int lo = 1, hi = n;
  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if (check(mid)) {
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  cout << "! " <<  lo << '\n';
  return 0;
} //Hajimemashite

