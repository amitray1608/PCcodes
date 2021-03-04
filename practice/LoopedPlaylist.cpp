
#include<bits/stdc++.h>

using namespace std;
#define int int64_t

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, s;
  cin >> n >> s;
  vector<int> a(n * 2);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
    a[i + n] = a[i];
  }
  
  int ans = 0;
  if (sum <= s) {
    ans = s / sum;
    s %= sum;
  }
  ans *= n;
  int curr = 0, j = 0;
  int mini = LLONG_MAX, pos = 0;
  for (int i = 0; i < 2 * n; i++) {
    curr += a[i];
    while (curr - a[j] >= s) {
      curr -= a[j];
      j++;
    }
    if (mini > i - j + 1 and curr >= s) {
      pos = j;
      mini = i - j + 1;
    }
  }
  ans += mini;
  cout << pos % n + 1 << " " << ans << '\n';
  return 0;
} //Hajimemashite
