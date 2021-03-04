#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  stack<array<int, 2>> fir, sec;

  auto add = [&](int x) {
    sec.push({x, __gcd(sec.top()[1], x)});
  };
  
  auto check = [&]() {
    int gc = (__gcd(sec.empty() ? 0 : sec.top()[1]);
    
  }

  auto remove = [&]() {
   if (fir.empty()) {
    while (!sec.empty()) {
      fir.push(sec.top());
      sec.pop();
    } 
   } 
   fir.pop();
  };

  int maxi = INT_MAX, ans = 0, j = 0;
  for (int i = 0; i < n; i++) {
    add(a[i]);
    ans = __gcd(ans, a[i]);
    while (j < i and __gcd(
    
  }

  return 0;
} //Hajimemashite
