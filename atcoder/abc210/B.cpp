
#include<bits/stdc++.h>

using namespace std;
#define int int64_t

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int n;
  cin >> n;
  string s;
  cin >> s;
  int count = 0;
  for (char c : s) {
    if (c == '1') break;
    count++;
  }
  if (~count & 1) {
    cout << "Takahashi" << '\n';
  } else {
    cout << "Aoki" << '\n';
  }
  return 0;
} //Hajimemashite

