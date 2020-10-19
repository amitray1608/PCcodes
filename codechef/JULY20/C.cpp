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
  char s[8][8];
  s[0][0] = 'O';
  int count = 1;
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      if(i == 0 and j == 0) continue;
      count++;
      // cout << count << endl;
      if(count > n){
        s[i][j] = 'X';
      } else {
        s[i][j] = '.';
      }
    
}  }
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++)
      cout << s[i][j];
    cout << endl;
  }
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