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
    vector<pair<int, int>> a(100, -1);
    for (int i = 0; i < n; i++) {
      cin >> a[i].first;
    }
    for (int i = 0; i < n; i++) {
      cin >> a[i].second;
    }

    for (int i = 0; i < 100; i++) {
      int x = a[i].first, l = a[i].second;
      if (x == -1) continue;
      int pos = 0;
      for (int j = i + 1; j < 100; i++) {
         int y = a[j].first;
         if (y == -1) continue;
         if (y < x) pos = j;
      }
      int dis = j - i + 1;
      count += (dis + l) / l;

    }

  }
  return 0;
}
