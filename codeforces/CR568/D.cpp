
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a.push_back({x, i});
  }
  if (n == 2) {
    cout << 1 << '\n';
    return 0;
  }
  sort(a.begin(), a.end());
  
  auto check = [&](int x) {
     
    return true;
  };

  if (a[1].first - a[0].first != a[2].first - a[1].first) {
    if (check(0)) {
      cout << a[0].second + 1 << '\n';
      return 0;
    }
    if (check(1)) {
      cout << a[1].second + 1 << '\n';
      return 0;
    }
    if (check(2)) {
      cout << a[2].second + 1 << '\n';
      return 0;
    }

  }
  int res = 0;
  bool found = false;
  int A = a[0].first, D = a[1].first - a[0].first;
  for (int i = 0; i < n; i++) {
    if (a[i].first != A + ((i) * D)) {
      if (!found) {
        found = true;
        res = a[i].second + 1;
      } else {
        res = -1;
        break;
      }
    }
  }
  if (res == 0) {
    cout << 1 << '\n';
  } else 
    cout << res << '\n';
  return 0;
} //Hajimemashite

