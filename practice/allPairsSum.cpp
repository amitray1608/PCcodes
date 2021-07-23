
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  vector<pair<int, int>> res;
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]]++;
  }
  for (auto i : mp) {
    int curr = i.first;
    if (curr > k / 2) continue;
    int left = k - curr;
    if (left == curr) {
      if (mp[curr] > 1) {
        res.push_back({curr, curr});
      }
    } else if (mp.find(left) != mp.end()) {
      res.push_back({left, curr}); 
    }
  }
  for (auto i : res) {
    cout << i.first << ' ' << i.second << "\n";
  }
  return 0;
} 

