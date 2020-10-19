#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

int dp[10][2][2];

int recc(string s, int pos = 0, int tight = 1, int flag = 0) {
  if(s.length() == pos) {
    return flag;
  } else if(dp[pos][tight][flag] != -1)
    return dp[pos][tight][flag];
  else if(tight) {
    int ans = 0;
    for(int i = 0; i <= s[pos] - '0'; i++) {
      int flg = flag;
      if(i == 3)
        flg = 1;
      if(i == s[pos]-'0')
        ans += recc(s, pos+1, 1, flg); 
      else
        ans += recc(s, pos+1, 0, flg);
    }
  
    return dp[pos][tight][flag] = ans;
  } else {
    int ans = 0;
    for(int i = 0; i <= 9; i++) {
      int f = flag;
      if(i == 3)
        f = 1;
      ans += recc(s, pos+1, 0, f);
    }
    return dp[pos][tight][flag] = ans;
  }
}


void solve(){
  int l;
  cin >> l;
  string s = to_string(l);
  memset(dp, -1, sizeof dp);
  int ans = recc(s);
  cout << l - ans << endl;
}

int main(){
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1, tt = 0;
		cin >> t;
		while(t--){
			//tt++;
			//cout << "Case #" << t << ": ";
			solve();
		}
	return 0;
}
