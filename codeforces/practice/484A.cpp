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
  bool flag = true;
  for(int i = 0; i < n-1; i++) {
    if(s[i] == '1'){
      if(i > 0 and s[i-1]=='1')
        flag = 0;
      if(i+1 < n and s[i+1] == '1')
        flag = 0;
    }else{
      if( (i==0 or (i > 0 && s[i-1]=='0') ) and (i==n-1 or (i+1<n and s[i+1]=='0') ) )
        flag=0;
    }
  }
    cout << (flag ? "Yes" : "No") << endl;
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