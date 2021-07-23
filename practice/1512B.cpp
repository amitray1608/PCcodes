
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
    string s[n];
    for (auto &i : s) {
      cin >> i;
    
    }
    array<int, 2> f[2];
    int c = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (s[i][j] == '*') {
          f[c][0] = i;
          f[c][1] = j;
          c++;
        }
      }
    }
    if (f[0][0] == f[1][0]) {
      if (f[0][0] > 0) {
        s[0][f[0][1]] = '*';
        s[0][f[1][1]] = '*';
      } else {
        s[n - 1][f[0][1]] = '*';
        s[n - 1][f[1][1]] = '*';
      }
    } else if (f[0][1] == f[1][1]) {
      int newy = f[1][1] + 1;
      s[f[0][0]][newy % n] = '*';
      s[f[1][0]][newy % n] = '*';
    } else {
      s[f[0][0]][f[1][1]] = '*';
      s[f[1][0]][f[0][1]] = '*';
    }
    for (auto i : s) {
      cout << i << '\n';
    }
  }
  return 0;
} //Hajimemashite

