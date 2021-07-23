
#include<bits/stdc++.h>

using namespace std;
int dx4[] = {1, -1, -1, 1}; 
int dy4[] = {1, -1, 1, -1}; //4 Direction
int dx8[] = {1, 1, 0, -1, -1, -1, 0, 1}; 
int dy8[] = {0, 1, 1, 1, 0, -1, -1, -1}; //8 direction

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  if (x1 == x2 and y1 == y2) {
    cout << 0 << ' ' << 0 << ' ' << 0 << '\n';
    return 0;
  }

  vector<int> res(3, 0);

  auto rook = [&]() {
    if (x1 == x2 or y1 == y2)
      return 1;
    else 
      return 2;
  };

  auto bishop = [&]() {
    if ((x1 + y1) & 1 and (x2 + y2) & 1) {
      if (abs(x1 - x2) ==  abs(y1 - y2))
        return 1;
      else 
        return 2;
    } else if (~(x1 + y1) & 1 and ~(x2 + y2) & 1) {
      if (abs(x1 - x2) ==  abs(y1 - y2))
        return 1;
      else 
        return 2;
    } else {
      return 0;
    }
  };

  auto king = [&]() {
    return max(abs(x1 - x2), abs(y2 - y1));
  };

  res[0] = rook();
  res[1] = bishop();
  res[2] = king();

  cout << res[0] << ' ' << res[1] << ' ' << res[2] << '\n';
  
  return 0;
} //Hajimemashite
