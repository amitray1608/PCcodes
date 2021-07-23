
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int &i : a) {
      cin >> i;
      sum += i;
    }
    sum -= n;
    int res = sum;
    if (sum == 0)
      res = 0;
    else if (sum < 0) 
      res = 1;
    cout << res << '\n';
  }	
  return 0;
} //Hajimemashite

