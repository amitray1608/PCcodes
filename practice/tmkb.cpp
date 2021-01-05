#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  long long count = 0;
  int f[n][26] = {0};
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      f[i][s[i] - 'a']++;
    }
  }

  auto Get = [&](int c, int l, int r) {
    if(r < l) return 0;
    return f[r][c] - (l ? f[l - 1][c] : 0);
  };

  for(int i = 0; i < n; i++) {
    for(int j = i + 2; j < n; j++) {
      if(s[i] == s[j]) {
        for(int k = 0; k < 26; ++k) {
          count += 1LL * Get(k, i + 1, j - 1) * Get(k, j + 1, n - 1);
        }
      }
    }
  }

  cout << count << '\n';
 return 0;
}
