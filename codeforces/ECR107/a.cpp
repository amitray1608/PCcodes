
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int n;
    cin >> n;
    array<int, 2> a, b;
    a[0] = b[0] = a[1] = b[1] = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (x == 1) {
        a[0]++;
      } else if (x == 2) {
        b[1]++;
      } else {
        if (a[0] >= a[1]) {
          a[0]++;
        }
      }
    }
    cout << a[0] << '\n';
  }
  return 0;
} //Hajimemashite

