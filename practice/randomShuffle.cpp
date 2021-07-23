
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n), ind(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ind[i] = i;
  }
  for (int i = 0; i < n; i++) {
    int x = rand() % n;
    swap(ind[i], ind[x]);
  }

  for (int i = 0; i < n; i++) {
    cout << a[ind[i]] << ' ';
  }
  
  return 0;
} 

