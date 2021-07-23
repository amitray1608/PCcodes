
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  long long n;
  cin >> n;
  long long a[11]{};
  a[1] = 1;
  for (int i = 2; i < 11; i++) {
    a[i] = a[i - 1] * i;
  }
  long long count = 0;
  for (int i = 10; i >= 1; i--) {
    if (n >= a[i]) {
      count += n / a[i];
      n %= a[i];
    }
  }
  cout << count << "\n";
  return 0;
} //Hajimemashite

