
#include <bits/stdc++.h>

using namespace std;

int calc(vector<int> &curr, vector<int> &reqd) {
  int count = 0;
  int n = curr.size(), m = reqd.size();
  int done = 0;
  for (int i = m - 1; i >= 0; i--) {
    done += binary_search(curr.begin(), curr.end(), reqd[i]);
  }
  count = done;
  for (int i = 0; i < m; i++) {
    done -= binary_search(curr.begin(), curr.end(), reqd[i]);
    int it = upper_bound(curr.begin(), curr.end(), reqd[i]) - curr.begin();
    int temp = upper_bound(reqd.begin(), reqd.end(), reqd[i]) - reqd.begin();
    temp -= upper_bound(reqd.begin(), reqd.end(), reqd[i] - it) - reqd.begin();
    count = max(count, done + temp);
  }
  return count;
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> posa, nega;
  vector<int> posb, negb;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x < 0) nega.push_back(-1 * x);
    else posa.push_back(x);
  }
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    if (x < 0) negb.push_back(-1 * x);
    else posb.push_back(x);
  }
  reverse(nega.begin(), nega.end());
  reverse(negb.begin(), negb.end());
  int ans = calc(posa, posb) + calc(nega, negb);
  cout << ans << '\n';
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

