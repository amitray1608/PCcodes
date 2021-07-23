
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int maxi = 0;
  for (int i = 0; i < n - 1; i++) {
    maxi = max(maxi, a[i + 1] - a[i]);
  }
  cout << maxi << '\n';
  
  return 0;
} 

