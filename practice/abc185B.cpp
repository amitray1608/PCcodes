#include<bits/stdc++.h>

using namespace std;

int main() {
  int n, m, t;
  cin >> n >> m >> t;
  int curr = n, tt = 0;
  bool ok = true;
  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    curr = curr - ((a - tt) + 1);
    tt = a;
    if(curr < 0) {
      ok = false;
    }
    curr = max(n, curr + (b - a) + 1);
    tt = b;
  }
  curr -=  ((t - tt) + 1);
  if(curr <= 0) ok = false;
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}
