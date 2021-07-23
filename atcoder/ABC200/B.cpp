
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  long long n, k;
  cin >> n >> k;
  while (k--) {
    if (n % 200 == 0) {
      n /= 200;
    } else {
      n *= 10;
      n += 2;
      n *= 100;
    }
  }
  cout << n << '\n';
  return 0;
} //Hajimemashite

