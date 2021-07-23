
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  const int maxn = 1e5 + 1;
  int spf[maxn + 1]{0};
  vector<int> prime;
  for (int i = 2; i <= maxn; i++) {
    if (spf[i] == 0) {
      spf[i] = i;
      prime.push_back(i);
    }
    for (int j = 0; j < (int)prime.size() && prime[j] <= spf[i]  && i * prime[j] < maxn 
; j++) {
      spf[i * prime[j]] = prime[j];
    }
  }
  for (int i : prime) {
    cout << i << ' ';
  } cout << '\n';
  return 0;
} //Hajimemashite

