#include <iostream>

int get_change(int m) {
  //write your code here
  int ans = m / 10;
  m %= 10;
  ans += m / 5;
  m %= 5;
  ans += m;
  return ans;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
