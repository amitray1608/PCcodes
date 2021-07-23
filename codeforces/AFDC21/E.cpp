
#include<bits/stdc++.h>

using namespace std;
int res = 0;
int dx[] = {1, 0, -1, 0}; int dy[] = {0, 1, 0, -1}; //4 Direction
int n, m;
vector<string> s(n);
int inf = 1e9;
int recc(int i, int j, int count) {
  if (i < 0 or j < 0 or i >= n or j >= m) return 0;
  if (i == n - 1 and j == m - 1) {
    if (s[i][j] == '*') count++;
    return count;
  }
  int curr1 = recc(i + 1, j, count + (s[i][j] == '*'));
  int curr2 = recc(i, j + 1, count + (s[i][j] == '*'));
  if (!curr1) return curr2;
  if (!curr2) return curr1;
  return min(curr1, curr2);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  cin >> n >> m;
  s.resize(n);
  for (auto &i : s) {
    cin >> i;
  }
  int maxi = recc(0, 0, 0);
  cout << maxi << '\n';
  return 0;
} //Hajimemashite

