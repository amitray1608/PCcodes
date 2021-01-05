#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t;
  cin >> t;
  while(t--) {
    int n, k, x, y;
    cin >> n >> k >> x >> y; k--;
    pair<int, int> c[4];
    if(x == y) {
      cout << n << ' ' << n << '\n';
    } else if(x > y) {
      c[0].first = n;
      c[0].second = (n - x) + y;
      c[1].first = c[0].second;
      c[1].second = c[0].first;
      c[2].first = 0;
      c[2].second = (n - c[1].first);
      c[3].first = c[2].second;
      c[3].second = c[2].first;
      int p = k % 4;
      if(k < 4) {
        
      }
//      for(int i = 0; i < 4; i++) {
//        cout << c[i].first << ' ' << c[i].second << '\n';
//      }
      cout << c[p].first << ' ' << c[p].second << '\n';
    } else {
      c[0].second = n;
      c[0].first = (n - y) + x;
      c[1].first = c[0].second;
      c[1].second = c[0].first;
      c[2].second = 0;
      c[2].first = (n - c[1].second);
      c[3].first = c[2].second;
      c[3].second = c[2].first;
      int p = k % 4;
//      for(int i = 0; i < 4; i++) {
//        cout << c[i].first << ' ' << c[i].second << '\n';
//      }
      cout << c[p].first << ' ' << c[p].second << '\n';
    }
  }
  return 0;
}
