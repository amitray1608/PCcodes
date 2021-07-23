
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    set<int> M, T;
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'T') T.insert(i);
      if (s[i] == 'M') M.insert(i);
    }
    int sm = M.size();
    int countT = 0, countM = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'T') countT++;
      else countM++;
      if (countM > countT) {
        ok = false;
        break;
      }
    }
    countT = 0, countM = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] == 'T') countT++;
      else countM++;
      if (countM > countT) {
        ok = false;
        break;
      }
    }
    ok &= (sm == n / 3);
    cout << (ok ? "YES" : "NO") << '\n';
  }	
  return 0;
} //Hajimemashite


