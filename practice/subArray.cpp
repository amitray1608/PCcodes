
#include<bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &i : a) {
    cin >> i;
  }
  
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      for (int k = i; k <= j; k++) {
        cout << a[k] << ' ';
      } cout << '\n';
    }
  }
  return 0;
} 

