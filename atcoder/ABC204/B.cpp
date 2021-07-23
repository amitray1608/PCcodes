
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int n;
  cin >> n;
  int a[n];
  for (int &i : a) cin >> i;
  int ans = 0;
  for (int i : a) {
    if (i <= 10) continue;
    else ans += i - 10;
  }
  cout << ans << '\n';
  return 0;
} //Hajimemashite

