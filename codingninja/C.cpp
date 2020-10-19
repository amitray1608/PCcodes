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
  int cost;
  int a[26];
  for(int &i : a) cin >> i;
  cin >> cost;
  string s = "";
  for(int i = 25; i >= 0; i--){
      while(a[i] <= cost){
        s = s + ((char)(97+i));
        cost -= a[i];
      }
      if(cost == 0) {
          break;
      }
  }
  if(s.size() != 0)    
    cout << s << endl;
  else 
    cout << 0 << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while(t--){
    //tt++;
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  

  