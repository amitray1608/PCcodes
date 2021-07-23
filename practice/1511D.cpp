
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  int n, k;
  cin >> n >> k;
  string res = "";
  vector<vector<int>> count(26, vector<int>(26, 0));
  function<void(int, int)> recc = [&](int i, int c) {
    res += char('a' + c);
    if (i == n - 1) return;
    int next = -1;
    for (int j = 0; j < k; j++) {
      if (next == -1 or count[c][next] > count[c][(c + j) % k]) 
        next = (c + j) % k;
    }
    count[c][next]++;
    recc(i + 1, next);
  };
  recc(0, 0);
  cout << res << '\n';
  return 0;
} //Hajimemashite

