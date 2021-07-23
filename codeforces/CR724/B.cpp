
#include<bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  string c = "a";
  bool found = false;
  for (int i = 0; i < 26; i++) {
    found = false;
    for (int j = 0; j < n; j++) {
      if (s[j] - 'a' == i) found = true;
    }
    if (!found) {
      cout << char('a' + i) << '\n';
      return;
    }
  }

  char x[2];
  found = false;
  for (int i = 0; i < 26; i++) {
    x[0] = char('a' + i);
    for (int j = 0; j < 26; j++) {
      x[1] = char('a' + j);
      found = false;
      for (int k = 0; k < n - 1; k++) {
        if (s[k] - 'a' == i and s[k + 1] - 'a' == j) {
          found = true;
          break;
        }
      }
      if (!found) {
        cout << x[0] << x[1] << '\n';
        return;
      }
    }
  }
  
  char r[3];
  found = false;
  for (int i = 0; i < 26; i++) {
    r[0] = char('a' + i);
    for (int j = 0; j < 26; j++) {
      r[1] = char('a' + j);
      for (int l = 0; l < 26; l++) {
        r[2] = char('a' + l);
        found = false;
        for (int k = 0; k < n - 2; k++) {
          if (s[k] - 'a' == i and s[k + 1] - 'a' == j and s[k + 2] - 'a' == l) {
            found = true;
            break;
          }
        }
        if (!found) {
          cout << r[0] << r[1] << r[2] << '\n';
          return;
        }
      }
    }
  }

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    solve();   
  }	
  return 0;
} //Hajimemashite

