
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  
  vector<vector<int>> pre(27, vector<int>(26, 0));
  pre[1][25] = pre[0][25] = 1;

  for (int i = 1; i < 27; i++) {
  int sum = 0;
  for (int j = 24; j >= 0; j--) 
    sum += pre[i - 1][j + 1], pre[i][j] = sum;
  }
  pre[0][25] = 0;
  for (int i = 1; i < 27; i++) {
    pre[i][0] += pre[i - 1][25];
    for (int j = 1; j < 26; j++) 
      pre[i][j] += pre[i][j - 1];
  }

  int t = 1;
  //cin >> t;
  while(t--) {
  
    string s;
    cin >> s;
    int n = s.length();

    for (int i = 1; i < n; i++) { 
      if (s[i] <= s[i - 1]) {
        cout << "0\n";
        return 0;
      }
    }
    int res = 1;

    for (int i = 0; i < n; i++) {
      int sum = 0;
      int idx = s[i] - 'a';
      int l = n - i;
      if (i) 
        sum = pre[l][s[i - 1] - 'a'];
      if (!idx) 
        l--, idx = 26;
      idx--;
      res += pre[l][idx] - sum;
    }

    cout << res << "\n";
  }
  return 0;
} //Hajimemashite
