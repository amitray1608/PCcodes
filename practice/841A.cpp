
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int f[26]{0};
  bool ok = true;
  for (char c : s) {
    f[c - 'a']++;
    if (f[c - 'a'] > k) 
      ok = false;
  }
  cout << (ok ? "YES" : "NO") << '\n';
  
  return 0;
} //Hajimemashite
