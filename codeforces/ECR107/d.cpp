
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int n, k;
  cin >> n >> k;
  string res = "";
  for (int l = 0; l < 2; l++) {
    for (int i = 0; i < k; i++) {
      for (int j = i + 1; j < k; j++) {
        res += char('a' + i);
        res += char('a' + j);
      }
    }
  }
  while (res.size() < n) {
    res += 'a';
  }
  res.erase(res.begin() + n, res.end());
  cout << res << '\n'; 
  return 0;
} //Hajimemashite

