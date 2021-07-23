
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &i : a) {
    cin >> i;
  }
  int i = 1e3 * -1;
  while (i < 1e3 + 1) {
    if (!i) {
      i++;
      continue;
    }
    int count = 0;
    for (int j : a) {
      float x = j / (float)i;
      if (x > 0) count++;
    }
    if (count >= ceil(n / 2.0)) {
      cout << i << '\n';
      return 0;
    }
    i++;
  }
  cout << 0 << '\n';
  return 0;
} //Hajimemashite

