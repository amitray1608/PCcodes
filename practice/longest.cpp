
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  int arr1[n], arr2[n];
  for (int i = 0; i < n; i++) {
      cin >> arr1[i];
  }
  for (int i = 0; i < n; i++) {
  cin >> arr2[i];
  }
  int arr[n]; 
  for (int i = 0; i < n; i++)  
      arr[i] = arr1[i] - arr2[i]; 
  
  map<int, int> mp;
  int sum = 0;     
  int max_len = 0; 
  for (int i = 0; i < n; i++)  {  
    sum += arr[i];  
    if (sum == 0)  
      max_len = i + 1;  
    if (mp.find(sum) != mp.end())  
      max_len = max(max_len, i - mp[sum]);  
    else
      mp[sum] = i;  
  } 
    cout << max_len;  
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
  //cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite


