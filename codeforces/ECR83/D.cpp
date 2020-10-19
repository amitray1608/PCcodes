//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
int dp[1000];
int a[1000];
int n;
int lis(int i)
{
	  if(i == n)
		return 0;
	 if(dp[i]!=-1)
		return dp[i];
	 int ans = 1;
	 for(int j=i+1; j<n; j++){
	 	if(a[i] < a[j])
	 	ans = max(ans, lis(j)+1);
	 }
	 return dp[i] = ans;
}
void solve(){
	   for(int i=0;i<1000;i++)
	   dp[i] = -1;
       cin >> n;
       for(int i=0; i<n; i++)
       	   cin >> a[i];
       for(int i=0; i<n; i++)
		dp[i] = lis(i);
       
       cout << *max_element(dp,dp+n);
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		//int t = 1;
		cin >> t;
		while(t--){
			solve();
		}
	return 0;
}
