
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<int>> a(n + 1);
  for (int i = 0; i < n; i++) {
    int u, c;
    cin >> u >> c;
    a[c].push_back(u);
  }
  for (int i = 0; i < n; i++) {
    sort(a[i].begin(), a[i].end());
  }
  long long mini = 0;
  
  return 0;
} //Hajimemashite

