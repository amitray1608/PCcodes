
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  
  int n, k;
  cin >> n >> k;
  int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int mini = INT_MAX, sum = 0, j = 0;
  
  for (int i = 0; i < n; i++) {
    sum += a[i];
    
    while (sum - a[j] >= k) 
      sum -= a[j++];
    
    if (sum >= k)
      mini = min(i - j + 1, mini);
  }

  cout << mini << '\n';

  return 0;
} //Hajimemashite
