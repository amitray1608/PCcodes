
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int n;
  cin >> n;
  stack<array<int, 2>> odd, even;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if ((i + j) & 1) {
        odd.push({i, j});
      } else {
        even.push({i, j});
      }
    }
  }

  auto print = [](int tp, int x, int y) {
    cout << tp << ' ' << x << ' ' << y << endl;
  };

  while (odd.size() and even.size()) {
    int inp;
    cin >> inp;
    if (inp > 1) {
      auto [x, y] = odd.top();
      odd.pop();
      print(1, x, y);
    } else {
      auto [x, y] = even.top();
      even.pop();
      print(2, x, y);
    }
  }

  while (odd.size() or even.size()) {
    int inp;
    cin >> inp;
    if (odd.size()) {
      auto [x, y] = odd.top();
      odd.pop();
      if (inp > 1) {
        print(1, x, y);
      } else {
        print(3, x, y);
      }
    } else {
      auto [x, y] = even.top();
      even.pop();
      if (inp != 2) {
        print(2, x, y);
      } else {
        print(3, x, y);
      }
    }
  }
  
  return 0;
} //Hajimemashite

