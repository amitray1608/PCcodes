//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void solve(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  stack <char> ss;
  // int count = 0;
  for(char c : s){
    if(!ss.empty()){
      if(ss.top() == '(' and c == ')')
        ss.pop();
      else
        ss.push(c);
    } else {
      ss.push(c);
    }
  }
  cout << (int)ss.size()/2 << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while(t--){
    //tt++;
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  