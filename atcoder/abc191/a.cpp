#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x == k) continue;
    cout << x << ' ';
  }
  cout << '\n';
  return 0;
} //Hajimemashite
