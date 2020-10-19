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
  string s;
  cin >> s;
  int n = (int)s.length();
  bool table[n][n];
  memset(table, false, sizeof table);
  for(int i = 0; i < n; i++)
    table[i][i] = true;
  int maxi = 1;
  for(int i = 0; i < n-1; i++){
    if(s[i] == s[i+1]) {
      table[i][i+1] = true;
      maxi = 2;
    }
  }

  for(int k = 3; k <= n; k++) {
    for(int i = 0; i < n-k+1; i++) {
      int j = i+k-1;
      if(table[i+1][j-1] and s[i] == s[j]){
        table[i][j] = true;
        maxi = k;
      }
    }
  }
  cout << maxi << endl;
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