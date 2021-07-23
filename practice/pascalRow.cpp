
#include<bits/stdc++.h>

using namespace std;

void pascal(int n) {
  int num = 1;
  int den = 1;
  cout << 1 << ' ';
  for (int i = 1; i < n; i++) {
    num *= (n - i);
    den *= i;
    cout << num / den << ' ';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int n;
  cin >> n;
  pascal(n);
  return 0;
} //Hajimemashite

