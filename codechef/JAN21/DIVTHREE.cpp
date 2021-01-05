#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t;
  cin >> t;
  while(t--) {
    long long n, k, d;
    cin >> n >> k >> d;
    vector<int> a(n);
    long long sum = 0;
    for(int &i : a) cin >> i, sum += i;
    long long day = sum/(1LL*k);
    cout << min(day, d) << '\n';
  }
  return 0;
}
