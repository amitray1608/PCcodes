//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
ll gcd(ll a, ll b){
  if (a == 0)
      return b;
  return gcd(b % a, a);
}
int x = 10;
ll lcm(ll a, ll b)  {
  return (a*b)/gcd(a, b);
}
void solve(){
  //int n;
  //cin >> n;
  //vector<ll> a;
  //ll ai;
  //for(int i = 0; i < n; i++){
    //cin >> ai;
    //a.push_back(ai);
  //}
  //vector<vector<ll> > dp(2, vector<ll>(n, 1));
  //dp[0][0] = a[0];
  //dp[1][0] = a[0];
  //dp[0][1] = gcd(a[0],a[1]);
  //dp[1][1] = lcm(a[0],a[1]);
  //for(int i = 2; i < n; i++){
    //dp[0][i] = gcd(dp[0][i-1],a[i]);
    //dp[1][i] = lcm(dp[0][i-1],gcd(dp[1][i-1],a[i]));
  //}
  //cout << dp[1][n-1] << "\n";
  vector<int>a(5, 0);
  a = vector<int>();
  a.push_back(12);
  a.push_back(13);
  a.front() += a.back();
  cout << a.front() << endl;
}

int main(){
	//#ifndef RAY
		//freopen("input.txt", "r", stdin);
	//#endif
		//ios::sync_with_stdio(false);
		//cin.tie(nullptr);
		//int t = 1;
		//cin >> t;
		//while(t--){
			//solve();
		//}
		int x = 20;
		{
			int x = 30;
			cout << x << :: i;
		}
	return 0;
}	
