#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(n), one, two;
  for(int &i : a) cin >> i;
  for(int &i : b) cin >> i;
  for(int i = 0; i < n; i++) {
    (b[i] == 1 ? one.push_back(a[i]) : two.push_back(a[i]));
  }
  sort(one.rbegin(), one.rend());
  sort(two.rbegin(), two.rend());
  long long sum = accumulate(a.begin(), a.end(), 0LL);
  if(sum < m) {
    cout << -1 << '\n';
    return;
  }
  int res(INT_MAX);
  sum = accumulate(two.begin(), two.end(), 0LL);
  int j = 0;
  int n1 = (int)one.size();
  int n2 = (int)two.size();
  for (int i = n2; i >= 0; i--) {
    while(j < n1 && sum < m) {
      sum += one[j];
      j += 1;
    }
    if (sum >= m) {
      res = min(res, 2 * i + j);
    }
    if (i > 0) {
      sum -= two[i - 1];
    }
  }
  cout << res << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite


