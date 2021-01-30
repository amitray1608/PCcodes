#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if(n < 3) {
    cout << 0 << '\n';
    return;
  }
  vector<int> curr(n, -1); 
  int count = 0;
  for (int i = 1; i < n - 1; i++) {
    if(a[i] > a[i - 1] and a[i] > a[i + 1]) curr[i] = 1, count++;
    else if(a[i] < a[i - 1] and a[i] < a[i + 1]) curr[i] = 0, count++; 
  }

  auto valid = [&](int i) {
    if(i <= 0 || i >= n - 1) return 0;
    if(a[i - 1] < a[i] and a[i + 1] < a[i]) return 1;
    if(a[i - 1] > a[i] and a[i + 1] > a[i]) return 1;
    return 0;
  };
  
  int ans = 0;
  for (int i = 1; i < n - 1; i++) {
    int mini = 0, c = a[i];
    if(curr[i] != -1) {
      mini = 1;
      if(curr[i - 1] != -1) mini++;
      if(curr[i + 1] != -1) mini++;
      int minix = mini;
      a[i] = a[i - 1];
      mini -= valid(i - 1), mini -= valid(i), mini -= valid(i + 1);
      a[i] = a[i + 1];
      minix -= valid(i - 1), minix -= valid(i), minix -= valid(i + 1);

      mini = max(mini, minix);
    }
    a[i] = c;
    ans = max(ans, mini);
  }
  cout << max(0, count - ans) << '\n';
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

