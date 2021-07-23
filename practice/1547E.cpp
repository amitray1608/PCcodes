
#include<bits/stdc++.h>

using namespace std;
#define int int64_t
const int inf = 1e14;

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(k), T(k);
    for (auto &i : a) {
      cin >> i.first;
    }
    for (int i = 0; i < k; i++) {
      cin >> T[i].first;
      T[i].second = a[i].first;
      a[i].second = T[i].first;
    }
    sort(a.begin(), a.end());
    sort(T.begin(), T.end());
    vector<int> res(n, inf);
    
    int maxi = inf;
    auto check = [&](int mid, int x) {
      int cost = T[mid].first + abs(T[mid].second - x);
      if (maxi > cost) {
        maxi = cost;
        return true;
      }
      return false;
    };

    auto check1 = [&](int mid, int x) {
      int cost = a[mid].second + abs(a[mid].first - x);
      if (maxi > cost) {
        maxi = cost;
        return true;
      }
      return false;
    };

    for (int i = 0; i < n; i++) {
      int l = 0, r = k - 1;
      maxi = inf;
      while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid, i + 1)) {
          r = mid - 1;
        } else {
          l = mid + 1;
        }
      }
      check(l, i + 1);
      check(r, i + 1);
      res[i] = maxi;
    }
    for (int i = 0; i < n; i++) {
      int l = 0, r = k - 1;
      maxi = inf;
      while (l <= r) {
        int mid = (l + r) / 2;
        if (check1(mid, i + 1)) {
          r = mid - 1;
        } else {
          l = mid + 1;
        }
      }
      check1(l, i + 1);
      check1(r, i + 1);
      res[i] = min(res[i], maxi);
    }
    for (int i : res) cout << i << ' ';
    cout << '\n';
  }	
  return 0;
} //Hajimemashite

