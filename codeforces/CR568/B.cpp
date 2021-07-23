
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int n;
  cin >> n;
  for (int N = 0; N < n; N++) {
    string s, t;
    cin >> s >> t;
    bool ok = true;
    int j = 0;
    vector<pair<char, int>> p;
    for (char c : s) {
      if (p.size() > 0) {
        if (p.back().first == c) {
          p.back().second++;
        } else {
          p.push_back({c, 1});
        }
      } else {
        p.push_back({c, 1});
      }
    }
    vector<pair<char, int>> P;
    for (char c : t) {
      if (P.size() > 0) {
        if (P.back().first == c) {
          P.back().second++;
        } else {
          P.push_back({c, 1});
        }
      } else {
        P.push_back({c, 1});
      }
    }
    if (p.size() != P.size()) ok = false;
    else {
      for (int i = 0; i < p.size(); i++) {
        if (P[i].first != p[i].first) ok = false;
        if (P[i].second < p[i].second) ok = false;
      }
    }
    cout << (!ok ? "NO" : "YES") << '\n';
  }
  return 0;
} //Hajimemashite

