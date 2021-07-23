
#include <bits/stdc++.h> 

using namespace std;
#define int int64_t

int countGCD(int L, int R, int g) {
  L = (L + g - 1) / g;
  R = R/ g;
  int ans = 0;
  for (int i = L; i <= R; i++)
    for (int j = i; j <= R; j++)
      if (__gcd(i, j) == 1)
        ans++;
  return ans;
}


signed main() {
  int n, x; cin >> n >> x;
  cout << countGCD(1, n, x) << '\n';
	return 0;
}

