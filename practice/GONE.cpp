#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

ll dp[10][80][2];
ll prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};

bool check(int s) {
  for(int i : prime)
    if(i == s)
      return true;
  return false;
}

ll recc(string s, ll pos = 0, ll sum = 0, ll tight = 1) {
  ll ans = 0;
  if(pos == s.length())
    return (check(sum) ? 1 : 0);
  else if(dp[pos][sum][tight] != -1)
    return dp[pos][sum][tight];
  else if(tight) {
    ll ans = 0;
    for(int i = 0; i <= s[pos] - '0'; i++) { 
      if(i == s[pos] - '0')
        ans += recc(s, pos+1, sum+i, 1);
      else
        ans += recc(s, pos+1, sum+i, 0);
    }
    
    dp[pos][sum][tight] = ans;
    return ans;
  } else{ 
    ll ans = 0;
    for(int i = 0; i <= 9; i++) { 
      ans += recc(s, pos+1, sum+i, 0);
    }
    dp[pos][sum][tight] = ans;
    return ans;
  }
}

void solve(){
  ll l, r;
  cin >> l >> r;
  l--;
  string a = to_string(r);
  string b = to_string(l);
  memset(dp, -1, sizeof dp);
  ll rr = recc(a);
  memset(dp, -1, sizeof dp);
  ll li = recc(b);
  cout << rr - li << endl;
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
