#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 7;
vector<bool>is_prime;
vector<int> pre;
void seive(int n) {
  pre.resize(n + 1, 0);
  is_prime.assign(n+1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i <= n; i++) {
      if (is_prime[i]) {
          for (int j = i * i; j <= n; j += i)
              is_prime[j] = false;
      }
  }
  for (int i = 1; i <= n; i++) {
    if (is_prime[i]) {
      pre[i] = pre[i - 1] + 1;
    } else pre[i] = pre[i - 1];
  }
}




int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t;
  cin >> t;
  seive(maxn);
  while(t--) {
    int a, b;
    cin >> a >> b;
    cout << (pre[a] > pre[b] ? "Divyam" : "Chef") << '\n';
  }
  return 0;
} 
