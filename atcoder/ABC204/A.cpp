
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int x, y;
  cin >> x >> y;
  if (x == y) {
    cout << x << '\n';
  } else {
    int a[] = {0, 1, 2};
    for (int i : a) {
      if (i != x and i != y) {
        cout << i << '\n';
        return 0;
      }
    }
  }
  return 0;
} //Hajimemashite

