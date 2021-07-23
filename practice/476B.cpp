
#include<bits/stdc++.h>

using namespace std;

set<string> res;
string s, t;
int n;

void recc(string cp, int i) {
  if (i == n) {
    res.insert(cp);
    return;
  }
  if (cp[i] == '?') {
    cp[i] = '+';
    recc(cp, i + 1);
    cp[i] = '-';
    recc(cp, i + 1);
  } else {
    recc(cp, i + 1);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  cin >> s >> t;
  n = (int)s.size();
  recc(t, 0);
  int count = 0;
  for (char c : s) {
    if (c == '+') count++;
    else count--;
  }
  int ans = 0;
  int total = (int)res.size();
  for (auto i : res) {
    int sum = 0;
    for (char c : i) {
     sum += (c == '+' ? 1 : -1);
    }
    if (sum == count) ans++;
  }
  double prob = ((double)ans / (double)total);
  cout << fixed << setprecision(10);
  cout << prob;
  return 0;
} //Hajimemashite

