#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &i : a) cin >> i;
  
  int m;
  cin >> m;
  vector<int> b(m);
  for (int &i : b) cin >> i;
  
  if (n > m) {
    swap(n, m);
    swap(a, b);
  }
  
  int delta = 0, j = m - 1;
  vector<int> sum;
  for (int i = n - 1; i >= 0; i--) {
    int curr = a[i] + b[j--];
    if (delta) curr++;
    delta = curr / 10;
    sum.push_back(curr % 10);
  }

  for (;j >= 0; j--) {
    if (delta) b[j]++;
    delta = b[j] / 10;
    sum.push_back(b[j] % 10);
  }
  
  reverse(sum.begin(), sum.end());
  
  for (int &i : sum) cout << i;
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int t = 1;
  //cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
      //cout << "Case #" << tt << ": ";
      solve();
  }
  return 0;
} //Hajimemashite


