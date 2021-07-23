
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  ll n, m;
  cin >> n >> m;
  ll newn = 1;
  while (n--) {
    newn <<= 1;
    if (newn > m) {
      break;
    }
  }
  if (newn > m) {
    cout << m << '\n';
  } else {
    cout << m % newn << '\n';
  }
  
  return 0;
} //Hajimemashite

