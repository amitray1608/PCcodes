
#include<bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]]++;
  }
  int res = 0;
  for (auto i : mp) {
    if (i.second == 1) {
      res = i.first;
      break;
    }
  }
  cout << res << '\n';
  return 0;
} //Hajimemashite

