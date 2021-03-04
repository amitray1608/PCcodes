#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5 + 5;
int n, a[maxn], b[maxn], c[maxn];

long long inversion(int l, int r) {
  if (l == r) return 0;
  int m = l + ((r - l) >> 1);
  int x = l, y = m + 1;
  long long ans = inversion(l, m) + inversion(m + 1, r);
  for (int i = l; i <= r; i++) {
    if (x > m) {
      c[i] = b[y++];
    } else if (y > r) {
      c[i] = b[x++];
    }else if (b[x] > b[y]) {
      c[i] = b[y++];
      ans += m - x + 1;
    } else {
      c[i] = b[x++];
    }
  }
  for (int i = l; i <= r; i++) b[i] = c[i];
  return ans;
}

void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  long long count = inversion(0, n - 1);
  cout << count << '\n';
  for (int i = 0; i < n - 1; i++) {
    count += n - 1 - 2 * a[i];
    cout << count << "\n";
  }
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


