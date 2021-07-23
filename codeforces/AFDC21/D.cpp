
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  auto isPrime = [](int x) {
    for (int i = 2; i * i <= x; i++) 
      if (x % i == 0) return false;
    return true;
  };
  string s = to_string(n);
  reverse(s.begin(), s.end());
  n = stoi(s);
  string t = to_string(m);
  reverse(t.begin(), t.end());
  m = stoi(t);
  bool ok = s <= t;
  cout << (ok ? "YES" : "NO") << '\n';
  return 0;
} //Hajimemashite

