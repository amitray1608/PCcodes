
#include<bits/stdc++.h>

using namespace std;

vector<array<int, 2>> res;
void recc(int n, int f, int e, int m) {
  if (n == 1) {
    res.push_back({f, e});
    return;
  }
  recc(n - 1, f, m, e);
  res.push_back({f, e});
  recc(n - 1, m, e, f);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int n;
  cin >> n;
  recc(n, 1, 3, 2); 
  cout << res.size() << '\n';
  for (auto i : res) {
    cout << i[0] << ' ' << i[1] << '\n';
  }
  return 0;
} //Hajimemashite

