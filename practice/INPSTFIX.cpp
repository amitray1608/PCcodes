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
  stack<char> sig;
  string ans = "";
  auto prec = [&](char c) {
    if(c == '+' || c == '-') return 1;
    else if(c == '*' || c == '/') return 2;
    else if(c == '^') return 3;
    else return -1;    
  };

  for(char &c : s) {
    if(isalnum(c)) ans += c;
    else if(c == '(') sig.push(c);
    else if(c == ')') {
      while(sig.top() != '(') 
        ans += sig.top(), sig.pop();
      sig.pop();
    } else {
      while(!sig.empty() and prec(c) <= prec(sig.top()))
        ans += sig.top(), sig.pop();
      sig.push(c);
    }
  }
  while(!sig.empty())
    ans += sig.top(), sig.pop();
  cout << ans << endl;
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
