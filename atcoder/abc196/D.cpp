
#include<bits/stdc++.h>

using namespace std;

int h, w, a, b;
long long ans = 0;

void dfs(int i, int bit, int A, int B) {
  if (i == h * w) return (void)ans++;
  if (bit & 1 << i) {
    return dfs(i + 1, bit, A, B);
  }
  if (B) {
    dfs(i + 1, bit | 1 << i, A, B - 1);  
  }
  if (A) {
    if (i % w != w - 1 and ~bit & 1 << (i + 1)) {
      dfs(i + 1, bit | 1 << i | 1 << (i + 1), A - 1, B);
    }
    if (i + w < h * w) {
      dfs(i + 1, bit | 1 << i | 1 << (i + w), A - 1, B);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  cin >> h >> w >> a >> b;
  dfs(0, 0, a, b);
  cout << ans << '\n';
  return 0;
} //Hajimemashite

