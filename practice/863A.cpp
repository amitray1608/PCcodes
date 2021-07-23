
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  
  string s;
  cin >> s;
  int n = (int)s.length();
  int i = n - 1;
  while (i > 0 and s[i] == '0') i--;
  n = i + 1;
  bool ok = true;
  i = 0;
  while (i < n) {
    if (s[i] != s[n - i - 1]) 
      ok = false;
    i++;
  }
  cout << (ok ? "YES" : "NO") << '\n';
  
  return 0;
} //Hajimemashite
