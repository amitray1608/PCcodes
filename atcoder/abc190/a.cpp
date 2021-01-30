#include<bits/stdc++.h>

using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int ok = 0;
  if (a > b) { 
    ok = 1;
  } else if (b > a) {
    ok = 2;
  } else {
    if (c == 0) {
      ok = 2;
    } else {
      ok = 1;
    }
  }
  cout << (ok == 1 ? "Takahashi" : "Aoki") << '\n';
  return 0;
} //Hajimemashite
