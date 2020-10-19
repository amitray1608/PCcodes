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
  string s, p;
  cin >> s >> p;
  int fre[26] ={0};
  for(char c : s)
    fre[c-'a']++;
  string res = "";
  for(char c : p)
    fre[c-'a']--;
  int pos = -1;
  for(int i = 1; i < (int)p.size(); i++)
    if(p[i] != p[0]) {
      pos = i;
      break;
    }

  for(int i = 0; i < 26; i++) {
    string x = "";    
    while(fre[i]--) {
      x += (char)(i+'a');
    }
    if(i+'a' == p[0]) {
      if(pos == -1)
        res += x + p;
      else if(p[0] > p[pos])
        res += p + x;
      else
        res += x + p;
      continue;
    }
    res += x;
  }
  cout << res << endl;
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
1
cabracadabra S
cda P
aaaabbccdarr
*/