
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
    int l, r, s;
    cin >> l >> r >> s;
    map<int, int> mp;
    vector<int> a(n + 1, -1), res(n, -1);
    l -= 1;
    r -= 1;
    vector<int> reg(n);
    auto maintainSum = [&](int x, int v) {
      reg[x] = v;
    };
    auto check = [&]() {
      for (int i = l; i <= r; i++) {
        for (int c = 1; c <= n; c++) {
          if (a[c] != -1) continue;
          a[c] = i;
          int curmn = 0, curmx = 0;
          int left = r - i, pos = 1;
          while (left) {
            if (a[pos] == -1) {
              curmn += pos;
              left--;
            }
            pos++;
          }
          left = r - i;
          pos = n;
          while (left) {
            if (a[pos] == -1) {
              curmx += pos;
              left--;
            }
            pos--;
          }
          int currm = s - c;
          if (currm >= curmn and currm <= curmx) {
            res[i] = c;
            s -= c;
            break;
          } else {
            a[c] = -1;
          }
        }
        if (res[i] == -1) {
          return false;
        }
      }
      return true;
    };
    bool ok = true;
    ok = check();
//    for (int i : res) {
//      cout << i << ' ';
//    } cout << '\n';
    if (ok) {
      set<int> x;
      for (int i = 1; i <= n; i++) {
        if (a[i] == -1) x.insert(i);
      }
//      for (auto i : x) {
//        cout << i << ' ';
//      }
//      cout << '\n';
      for (int i = 0; i < n; i++) {
        if (i < l or i > r) {
          auto cur = x.begin();
          res[i] = *cur;
          x.erase(cur);
        }
      }
      for (int i = 0; i < n; i++) {
        cout << res[i] << ' ';
      }
      cout << '\n';
    } else {
      cout << -1 << '\n';  
    }
  }
  return 0;
} //Hajimemashite

