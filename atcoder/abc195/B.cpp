
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  
  ll a, b, w;
  cin >> a >> b >> w;
  w *= 1000;
  ll mini = INT_MAX, maxi = -1;
  for (ll i = 1; i < 1e6 + 1; i++) {
    if (a * i <= w and w <= b * i) {
      mini = min(mini, i);
      maxi = max(maxi, i);
    }
  }

  if (maxi == -1) { 
    cout << "UNSATISFIABLE"; 
  } else { 
    cout << mini << " " << maxi; 
  }
  return 0;
} //Hajimemashite


