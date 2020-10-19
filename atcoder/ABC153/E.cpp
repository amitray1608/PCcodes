//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
const int inf = 100000000;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
  
int knapSack(int W, int wt[], int val[], int n) 
{ 
   int i, w; 
   int K[n+1][W+1]; 
  ll ans = 0;
   // Build table K[][] in bottom up manner 
   for (i = 0; i <= n; i++) 
   { 
       for (w = 0; w <= W; w++) 
       { 
           if (i==0 || w==0) 
               K[i][w] = 0; 
           else if (wt[i-1] <= w) {
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]); 
				ans+=val[i-1];
			}
           else{
                 K[i][w] = K[i-1][w]; 
				ans += val[i];
			}
       } 
   } 
  
   return ans; 
} 
void solve(){
	int h, n;
	cin >> h >> n;
	
	int a[n], b[n];
	for(int i = 0; i < n; i++){
		cin >> a[i] >> b[i];
	}
	int dp[n], dp2[n];
	memset(dp, inf, sizeof dp);
	dp[0] = 0;
	memset(dp2, 0, sizeof dp2);
	for(int i = 1; i < h; i++){
		for(int j = 0; j < n; j++){
			if(a[j] <= i && dp[i-a[j]]+1 < dp[i]){
				dp[i] = dp[i-a[j]]+1;
				dp2[i] = dp2[i-a[j]]+b[i];
			}
		}
	}
	cout << dp2[h];
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1;
		//cin >> t;
		while(t--){
			solve();
		}
	return 0;
}
