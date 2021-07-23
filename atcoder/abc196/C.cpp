
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  long long n;
  cin >> n;
  long long count = 0;
  for (long long i = 1; i <= (long long)1e6+1; i++) {
    if (i > n) break;
    string s = to_string(i);
    string res = s + s;
    long long N = stol(res);
    if (N <= n) {
      count++;
    }
  }
  cout << count << '\n';
  return 0;
} //Hajimemashite

