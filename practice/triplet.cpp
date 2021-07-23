
#include<bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  map<int, int> f;
  map<int, vector<int>> left;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    f[a[i]]++;
    left[a[i]].push_back(i);
  }
  long long count = 0;
  for (auto i : f) {
    int x = i.second - 2;
    for (int j = 1; j <= x; j++) 
      count += (j * (j + 1)) / 2;
  }
  for (auto i : left) {
    for (int j : i.second) {
      vector<int> tmp = left[i.first + 1];
      auto x = upper_bound(tmp.begin(), tmp.end(), j); 
      if (x == tmp.end()) continue;
      int pos = x - tmp.begin();
      int req = tmp.size() - pos;
      tmp = left[i.first + 2];
      auto y = upper_bound(tmp.begin(), tmp.end(), pos);
      if (y == tmp.end()) continue;
      pos = y - tmp.begin();
      int req2 = tmp.size() - pos;
      count += (req * req2);
    }
  }
  cout << count << '\n';
  return 0;
} 
