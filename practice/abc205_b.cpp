
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[x]++;
  }
  bool ok = true;
  for (int i = 1; i <= n; i++) {
    if (a[i] != 1) ok = false;
  }
  cout << (ok ? "Yes" : "No") << '\n'; 
  return 0;
} //Hajimemashite

