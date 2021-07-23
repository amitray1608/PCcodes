
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
    vector<int> a(n);
    int p[101] = {0};
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      p[a[i]]++;
    }
    int v = 0;
    for (int i = 1; i <= 101; i++) {
      if (p[i] == 1) {
        v = i;
        break;
      }
    }
    for (int i = 0; i < n; i++) {
      if (a[i] == v) {
        cout << i + 1 << '\n';
        break;
      }
    }
  }
  return 0;
} //Hajimemashite

