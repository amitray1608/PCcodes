
#include <bits/stdc++.h>

using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

void solve() {
  int n;
  cin >> n;
  minpq<int> mine, miner, cp;
  for (int i = 0; i < 2 * n; i++) {
    int x, y;
    cin >> x >> y;
    x = abs(x), y = abs(y);
    if (x > y)
     miner.push(x);
    else mine.push(y);
  }
  auto dist = [&](double x, double y) {
    return sqrtl(x * x + y * y);
  };

  cout << fixed << setprecision(15);
  long double res = 0;
  for (int i = 0; i < n; i++) {
    res += dist((double)mine.top(), (double)miner.top());
    mine.pop();
    miner.pop();
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


