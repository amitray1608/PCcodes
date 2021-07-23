
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int n;
  cin >> n;
  int ans = n / 100 + (n % 100 != 0);
  cout << ans << '\n';
  return 0;
} //Hajimemashite

