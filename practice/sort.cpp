
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &i : a) {
      cin >> i;
    }
    vector<int> b;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) 
        b.push_back(a[i] ^ a[j]);
    }
    sort(b.begin(), b.end());
    cout << b[k - 1] << '\n';
  }
  return 0;
} //Hajimemashite

