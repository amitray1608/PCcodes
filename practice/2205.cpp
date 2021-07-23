#include<bits/stdc++.h>

using namespace std;
int n, counts;
vector<string> ans;
bool vis[1 << 17];

void recc(string s) {
  if(counts == pow(2, n)) {
    return;
  }
  ans.push_back(s);
  int x = stoi(s, 0, 2);
  vis[x] = true;
  counts++;
  for (char &c : s) {
    if (c == '1') c = '0';
    else c = '1';
    x = stoi(s, 0, 2);
    if (!vis[x]) {
      recc(s);
      break;
    }
    if (c == '1') c = '0';
    else c = '1';
  }
}

int main() {
  cin >> n;
  memset(vis, false, sizeof vis);
  string c = "";
  for (int i = 0; i < n; i++) c += '0';
  recc(c);
  for(auto &i : ans)  cout << i << '\n';
  return 0;
}
