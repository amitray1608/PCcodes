#include <bits/stdc++.h>

using namespace std;

int query(int l, int r) {
  if (l == r) return -1;
  cout << "? " << l << ' ' << r << endl;
  int inp;
  cin >> inp;
  return inp;
}

void result(int x) {
  cout << "! " << x << endl;
}

void solve() {
  int n;
  cin >> n;
  int curr = query(1, n);
  int res;
  if (curr == query(1, curr)) {
    int l = 1, r = curr - 1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (query(mid, curr) == curr) {
        res = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
  } else {
    int l = curr + 1, r = n;
    while (l <= r) {
     int mid = (l + r) >> 1;
     if (query(curr, mid) == curr) {
       res = mid;
       r = mid - 1;
     } else {
       l = mid + 1;
     }
    }
  }
  result(res);
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


