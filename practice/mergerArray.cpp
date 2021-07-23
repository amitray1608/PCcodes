
#include<bits/stdc++.h>

using namespace std;

int n, m;

int get(int N) {
  if (N <= 1) {
    return 0;
  }
  return ceil(N / 2.0);
}

void merge() {
  int i, j, N = n + m;
  for (N = get(N); N > 0; N = get(N)) { // log N times
    for (i = 0; i + N < n; i++) {
      if (arr1[i] > arr1[i + N])
        swap(arr1[i], arr1[i + N]);
    }
    for (j = N > n ? N - n : 0; i < n and j < m; i++, j++) {
      swap(arr1[i], arr2[j]);
    }
    if (j < m) {
      for (j = 0; j + N < m; j++) {
        if (arr2[j] > arr2[j + N]) {
          swap(arr2[j], arr2[j + N]);
        }
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  	
  return 0;
} //Hajimemashite

