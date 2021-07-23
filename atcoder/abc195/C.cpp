
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  ll n;
  cin >> n;
  string s = to_string(n);
  ll len = s.size();
  ll count = n - (ll)pow(10LL, len - 1LL) + 1LL;
  if (len % 3LL == 0LL)  
    count = (len / 3LL - 1LL) * count;
  else 
    count = (len / 3) * count;
  ll k = len - 1LL, com = 0LL;
  while (k >= 3LL) {
    if (k % 3LL == 0LL) 
      com = k / 3LL - 1LL;
    else 
      com = k / 3LL;
    
    count += com * (ll)pow(10LL, k) - com * (ll)pow(10LL, k - 1LL);
    k--;
  }
  cout << count << '\n';
  return 0;
} //Hajimemashite


