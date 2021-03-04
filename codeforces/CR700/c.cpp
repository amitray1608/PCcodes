#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  //just for maxi
  auto query = [&](int x) {
    cout << "? " << x << endl;
    int inp;
    cin >> inp;
    return inp;
  };

  auto query2 = [&](int x) {
    cout << "! " << x << endl;
  };

  vector<int> res(n + 1, 0);
  int maxi = 0, curr = 0;
  while (true) {
    res[curr] = query(curr + 1);
    if (res[curr] > res[curr - 1] and curr == 1) {
      query2(curr);
      break;
    } else if (curr == n - 1) {
      if (res[curr] < res[curr - 1]) {
        query2(curr + 1);
        break;
      }
      else if (res[curr - 1] < min(res[curr], res[curr - 2])) {
        query2(curr);
        break;
      }
    } 
    if (res[curr - 1] < min(res[curr - 2], res[curr])) {
      query2(curr);
      break;
    }
    curr++;
  }
  cout << endl;
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


