
#include<bits/stdc++.h>

using namespace std;
#define int int64_t
int mini;

void recc(string s, int i) {
  if (i == 10) {
    int f = 0, fc = (10 >> 1);
    int ff = 0, ffc = (10 >> 1);
    for (int j = 0; j < 10; j++) {
      if (~ j & 1) 
        fc--, f += (s[j] == '1');
      else 
        ffc--, ff += (s[j] == '1');
      if (f - ff > ffc or ff - f > fc) mini = min(mini, j + 1);
    }
    return;
  }
  if (s[i] == '?') {
    s[i] = '0';
    recc(s, i + 1);
    s[i] = '1';
    recc(s, i + 1);
  } else {
    recc(s, i + 1);
  }
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    string s;
    cin >> s;
    mini = 10;
    recc(s, 0);
    cout << mini << '\n';
  }	
  return 0;
} //Hajimemashite

