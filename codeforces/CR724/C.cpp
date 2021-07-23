
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> res(n, 0);
    int countD = 0, countK = 0;
    map<array<int, 2>, int> mp;
    for (int i = 0; i < n; i++) {
      (s[i] == 'D' ? countD++ : countK++);
      int com = __gcd(countD, countK);
      int currD = countD / com;
      int currK = countK / com;
      res[i] = ++mp[{currD, currK}];
    }
    for (int i : res) {
      cout << i << ' ';
    }
    cout << '\n';
  }	
  return 0;
} //Hajimemashite

