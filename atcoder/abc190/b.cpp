#include<bits/stdc++.h>

using namespace std;

int main() {
  int n, s, d;
  cin >> n >> s >> d;
  bool ok = false;
  for (int i = 0; i < n; i++) {
    int u, v;
    cin >> u >> v;
    if (u < s and v > d) ok = true;
  }
  cout << (ok ? "Yes" : "No") << '\n';
  return 0;
} //Hajimemashite
