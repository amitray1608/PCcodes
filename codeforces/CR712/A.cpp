
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    string s;
    cin >> s;
    string ok;
    int n = (int)s.size();
    string front = "a" + s;
    string backk = s + "a";
    n++;
    auto check = [&](string k) {
      string res = "";
      for (int i = 0; i < n; i++) {
        if (k[i] != k[n - i - 1]) return k;
      }
      return res;
    };
    ok = check(front);
    if (ok == "")
      ok = check(backk);
    if (ok != "") {
      cout << "YES" << "\n";
      cout << ok << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
  return 0;
} //Hajimemashite

