

#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int sum = a[0], maxi = a[0];
  for (int i = 1; i < n; i++) {
    sum = max(a[i], sum + a[i]);
    maxi = max(maxi, sum);
//    sum += a[i];    
//    maxi = max(maxi, sum);
//    if (sum < 0) sum = 0;
  }

  cout << maxi << '\n';

  return 0;
} //Hajimemashite
