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
  int i = n-1;
  while(i >= 0){
    if(s[i] == '1'){
      int j = i+1;
      int count = 0;
      while(j < n && s[j] != '1'){
        if(s[j] == '0'){ 
          count++;
          if(count != 1){
            s[j] = '&';
          }
        }
        j++;
      }
      if(j!= i+1 && count > 0){
          s[i] = '&';
      }
    }
    i--;
  }
  string ans = "";
  for(i=0;i < n; i++){
      if(s[i] != '&'){
          ans += s[i];
      }
  }
  cout << ans << endl;
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