
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &i : a) cin >> i;
  int maxi = INT_MIN;
  for (int i = 0; i < n; i++) {
    double sq = sqrt(a[i]);
    if (ceil(sq) != floor(sq)) {
      maxi = max(maxi, a[i]);
    }
  }
  cout << maxi << '\n';
  
  return 0;
} //Hajimemashite

