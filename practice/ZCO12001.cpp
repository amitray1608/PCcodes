//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void solve() {
  // int n; cin >> n;
  string s; cin >> s;
  stack<char> exp;
  auto precedence = [](char x) {
    if(x == '+' || x == '-') return 1;
    if(x == '*' || x == '/') return 2;
    return 3;
  };
  s = '(' + s; s = s + ')';
  for(char& i: s) {
    if(isalnum(i)) {
      cout << i;
      continue;
    }
    if(i == '(') {
      exp.push(i);
      continue;
    }
    if(i == ')') {
      while(exp.top() != '(') {
        cout << exp.top();
        exp.pop();
      }
      exp.pop();
      continue;
    }
    if(exp.top() == '(' || precedence(exp.top()) < precedence(i)) exp.push(i);
    else {
      while(exp.top() != '(') {
        cout << exp.top();
        exp.pop();
      }
      exp.push(i);
    }
  }
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(10);
  int t = 1;
  cin >> t;
  for(int tt = 1; tt <= t; tt++) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  

/*
2
1
15
((A+B)*D)^(E-F)
19
A+(B*C-(D/E^F)*G)*H

2
((A*B)+(C/D))
(A*(B+(C/D)))
*/
