#include<bits/stdc++.h>

using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    string s[n];
    map<char, int> all;
    map<char, string> bach;
    map<char, int> howmany;
    for (auto &i : s) {
      cin >> i;
      all[i[0]]++;
      bach[i.substr(1)].push_back(i[0]);
    }
    for (auto i : bach) {
      for (auto j : i.second) {
        howmany[j] += i.second.size();  
      }
    }
//    for (auto i : howmany) {
//      cout << i.first << ' ' << i.second << '\n';
//    }
//    continue;
    long long count = n * (n - 1);
    for (int i = 0; i < 26; i++) {
      for (int j = 0; j < 26; j++) {
        if (i == j) continue;
        int cnt = 0, cnt1 = 0;
        for (auto i : bach
      }
    }
    cout << count << '\n';
//    for (auto i : bach) cout << i.first << ' ' << i.second << '\n'; 
  }
  return 0;
}
