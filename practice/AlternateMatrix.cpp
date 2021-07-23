
#include<bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  int a[n][5]; 
  int curr = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      a[i][j] = curr++;
    }
    if (i & 1) {
      swap(a[i][0], a[i][4]);
      swap(a[i][1], a[i][3]);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) 
      cout << a[i][j] << ' ';
    cout << '\n';
  }
  return 0;
} 

