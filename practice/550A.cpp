
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  string s;
  cin >> s;
  int ab = 0, ba = 0;
  int n = (int)s.size();
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == 'A' and !ab) {
      if (s[i + 1] == 'B') {
        i++;
        ab++;
      }
    } else if (s[i] == 'B' and !ba) {
      if (s[i + 1] == 'A') {
        i++;
        ba++;
      }
    }
  }
  if (ab && ba) {
    cout << "YES" << '\n';
    return 0;
  }
  ab = 0, ba = 0;
  for (int i = n - 1; i >= 1; i--) {
    if (s[i] == 'A' and !ba) {
      if (s[i - 1] == 'B') {
        ba++;
        i--;
      }
    } else if (s[i] == 'B' and !ab) {
      if (s[i - 1] == 'A') {
        ab++;
        i--;
      }
    }
  }
  if (ab && ba) {
    cout << "YES" << '\n';
  } else {
    cout << "NO" << '\n';
  }
  return 0;
} //Hajimemashite

