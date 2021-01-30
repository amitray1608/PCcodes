#include<bits/stdc++.h>

using namespace std;
int n;
vector<string> ans;

void recc(string s, int turn) {
  if(s.size() == n) {
    ans.push_back(s);
    return;
  }
  int x = turn ^ 1;
  if(turn&1) recc(s + '0', x), recc(s + '1', x);
  else recc( s + '1', x), recc(s + '0', x);
}

int main() {
  cin >> n;
  string c = "";
  recc(c, 0);
  for(auto &i : ans)  cout << i << '\n';
  return 0;
}
