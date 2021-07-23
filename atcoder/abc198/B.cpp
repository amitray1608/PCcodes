
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  string s;
  cin >> s;
  int n = (int)s.size();
  auto check = [&](string x) {
    int N = (int)x.size();
    for (int i = 0; i < N; i++) {
      if (x[i] != x[N - i - 1]) return false;
    }
    return true;
  };
  int count = 100;
  bool ok = check(s);
  while (count--) {
    s = "0" + s;
    ok |= check(s);
  }
  cout << (ok ? "Yes" : "No") << '\n';
  return 0;
} //Hajimemashite

