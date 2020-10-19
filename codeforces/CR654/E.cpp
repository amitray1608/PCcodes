//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

bool isprime(int n) {
  for(int i = 2; i *i < n; i++) 
    if(n%i == 0)
      return false;
  return true;
}

void solve(){
  string s;
  cin >> s;
  int n = (int)s.length();
  bool table[n][n];
  memset(table, false, sizeof table);
  int maxi = 1;
  for(int i = 0; i < n; i++)
    table[i][i] = true;
  int st = 0;
  for(int i = 0; i < n-1; i++){
    if(s[i] == s[i+1]) {
      table[i][i+1] = true;
      st = i;
      maxi = 2;
    }
  }

  for (int k = 3; k <= n; ++k) { 
    for (int i = 0; i < n - k + 1; ++i) { 
      int j = i + k - 1; 
      if (table[i + 1][j - 1] && s[i] == s[j]) { 
        table[i][j] = true; 
        if (k > maxi) { 
          st = i; 
          maxi = k; 
          deb(st);
          deb(maxi);
        } 
      } 
    } 
  } 
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++){
      cout << table[i][j] << ' ';
    }
    cout << endl;
  }
  if(maxi == 1){
    cout << "NOT PRIME" << endl;
    return;
  }
  cout << (isprime(maxi) ? "PRIME" : "NOT PRIME") << endl;
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