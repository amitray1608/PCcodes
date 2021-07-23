
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
    string x, y, z;
    cin >> x >> y >> z;
    string res = "";
    int N = (int)x.size() / 2;
    int count = 0;
    int three = 3 * N, two = 2 * N;
    for (int i = 0, j = 0, k = 0; count < three; count++) {
      int zero = 0, one = 0;
      if (two > i) (x[i] == '0' ? zero++ : one++);
      if (two > j) (y[j] == '0' ? zero++ : one++);
      if (two > k) (z[k] == '0' ? zero++ : one++);
      if (one < zero) {
        res += '0';
        if (i < two and x[i] == '0') i++;
        if (j < two and y[j] == '0') j++;
        if (k < two and z[k] == '0') k++;
      } else {
        res += '1';
        if (i < two and x[i] == '1') i++;
        if (j < two and y[j] == '1') j++;
        if (k < two and z[k] == '1') k++;
      }
    }
    cout << res << '\n';
  }	
  return 0;
} //Hajimemashite

