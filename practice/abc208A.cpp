
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int a, b;
  cin >> a >> b;
  bool ok = (a <= b and a * 6 >= b);
  cout << (ok ? "Yes" : "No") << '\n';
  return 0;
} //Hajimemashite

