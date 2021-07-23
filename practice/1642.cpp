
#include<bits/stdc++.h>

using namespace std;
#define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int n, target;
  cin >> n >> target;
  vector<array<int, 2>> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i][0];
    nums[i][1] = i + 1;
  }
  sort(nums.begin(), nums.end());
  for (int i = 0; i < n; i++) {
    auto [a, A] = nums[i];
    for (int j = i + 1; j < n; j++) {
      auto [b, B] = nums[j];
      int l = j + 1, r = n - 1;
      while (l < r) {
          auto [c, C] = nums[l];
          auto [d, D] = nums[r];
          int sum = a + b + c + d;
          if (sum == target) {
              cout << A << ' ' << B << ' ' << C << ' ' << D << '\n';
              return 0;
          } else if (sum < target) {
              l++;
          } else {
              r--;
          }
      }
    }
  }
  cout << "IMPOSSIBLE" << '\n'; 	
  return 0;
} //Hajimemashite


