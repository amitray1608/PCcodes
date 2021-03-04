#include<bits/stdc++.h>

using namespace std;
#define int int64_t
const int inf = LLONG_MAX;

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int &i : a) cin >> i;
  
  stack<array<int, 3>> f, s;

  auto add = [&](int x) {
    if (s.empty()) {
      s.push({x, x, x});
      return;
    }
    array<int, 3> tmp = {x, min(s.top()[1], x), max(s.top()[2], x)};
    s.push(tmp);
  };

  auto remove = [&]() {
    if (f.empty()) {
      int x = s.top()[0];
      f.push({x, x, x});
      s.pop();
      while (!s.empty()) {
        x = s.top()[0];
        array<int, 3> tmp = {s.top()[0], min(f.top()[1], x), max(f.top()[2], x)};
        f.push(tmp);
        s.pop();
      }
    }
    if (!f.empty())f.pop();
    return;
  };

  auto check = [&]() {
    int mn = min((s.empty() ? inf : s.top()[1]), (f.empty() ? inf : f.top()[1]));
    int mx = max((s.empty() ? 0 : s.top()[2]), (f.empty() ? 0 : f.top()[2]));
    return (mx - mn <= k);
  };

  int count = 0, j = 0;
  for (int i = 0; i < n; i++) {
    add(a[i]);
    while (!check()) {
//      cout << "OK" << endl;
//      return 0;
      remove();
      j++;
    }

    count += i - j + 1;
  }

  cout << count << '\n';

  return 0;
} //Hajimemashite
