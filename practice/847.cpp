
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  
  int n;
  cin >> n;
  string s[n];
  vector<vector<int>> v;
  v.resize(n, vector<int>(7, 0));
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    for (int j = 0; j < 7; j++) {
      v[i][j] = (s[i][j] == '1');
      if (i) {
        v[i][j] += v[i - 1][j];
      }
    }
  }
  int maxi = *max_element(v[n -1].begin(), v[n - 1].end());
  cout << maxi << '\n';

  return 0;
} //Hajimemashite
