
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int A, B, C;
  cin >> A >> B >> C;
  vector<int> a(A), b(B), c(C);
  for(int &i : a) cin >> i;
  for(int &i : b) cin >> i;
  for(int &i : c) cin >> i;


  auto check = [&](vector<int> x, vector<int> y, vector<int> z) {
    y.insert(y.end(), z.begin(), z.end());
    long long sumx = 0, sumy = 0;
    sumx = accumulate(x.begin(), x.end(), 0LL);
    sumy = accumulate(y.begin(), y.end(), 0LL);
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    long long ans = max(sumy + sumx - 2 * x[0] - 2 * y[0], sumy - sumx);
    return ans;
  };
  
  long long ans = max({check(a, b, c), check(b, a, c), check(c, b, a)});
  cout << ans << '\n';
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

