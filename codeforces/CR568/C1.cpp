
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int &i : a) {
    cin >> i;
  }
  int curr = 0;
  for (int i = 0; i < n; i++) {
    curr += a[i];
    if (curr <= m) cout << 0 << ' ';
    else {
      vector<int> arr;
      for (int j = 0; j < i; j++) 
        arr.push_back(a[j]);
      sort(arr.rbegin(), arr.rend());
      int sum = 0;
      for (int j = 0; j < arr.size(); j++) {
        sum += arr[j];
        if (curr - sum <= m) {
          cout << j + 1 << ' ';
          break;
        }
      }
    }
  }
  return 0;
} //Hajimemashite

