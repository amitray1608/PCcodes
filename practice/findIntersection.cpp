
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  sort(b.begin(), b.end());
  
  vector<int>intersect;
  for (int i = 0; i < n; i++) {
    if (binary_search(b.begin(), b.end(), a[i])) {
        intersect.push_back(a[i]);
    }
  }
  for (int ii : intersect) {
    cout << ii << ' ';
  }

  return 0;
} 

