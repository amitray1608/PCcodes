
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int a, b;
  cin >> a >> b;
  int c, d;
  cin >> c >> d;
  int maxi = INT_MIN;
  for (int i = a; i <= b; i++) {
    for (int j = c; j <= d; j++) {
      maxi = max(maxi, i - j);
    }
  }
  cout << maxi << '\n';
  return 0;
} //Hajimemashite

