
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int n; cin >> n;
  string s; cin >> s;
  string odd = "", even = "";
  for (int i = 0; i < n; i++) {
    if (i & 1) {
      odd += s[i];
    } else {
      even += s[i];
    }
  }
  string res = "";
  if (n & 1) {
    reverse(odd.begin(), odd.end());
    res = odd + even;
  } else {
    reverse(even.begin(), even.end());
    res = even + odd;
  }
  cout << res << '\n';
  return 0;
} //Hajimemashite

