
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int a, b;
    cin >> a >> b;
    string s, ss;
    cin >> s;
    ss = s;
    int n = (int)s.size();
    int curro = 0, currz = 0;
    for (char c : s) {
      if (c == '1') curro++;
      else currz++;
    }
    bool ok = true;
    auto check = [&]() {
      int i = 0, j = n - 1;
      for (;i < j; i++, j--) {
        if (s[i] == s[j] and s[i] != '?') continue;
        else if (s[i] != s[j] and s[i] != '?' and s[j] != '?') {
          return false;
        } else if (s[i] == '1') {
          if (!b) return false;
          s[j] = '1';
          b--;
        } else if (s[i] == '0') {
          if (!a) return false;
          s[j] = '0'; 
          a--;
        } else if (s[j] == '1') {
          if (!b) return false;
          s[i] = '1';
          b--;
        } else if (s[j] == '0') {
          if (!a) return false;
          s[i] = '0';
          a--;
        } else {
          if (a > b) {
            if (a < 2) return false;
            s[i] = s[j] = '0';
            a -= 2;
          } else {
            if (b < 2) return false;
            s[i] = s[j] = '1';
            b -= 2;
          }
        }
      }
      return true;
    };

    if (currz > a or curro > b or a + b > n) ok = false;
    else {
      a -= currz;
      b -= curro;
      ok = check();
    }
    if (ok) {
      cout << s << '\n';
    } else {
      cout << -1 << '\n';
    }
  }
  return 0;
} //Hajimemashite

