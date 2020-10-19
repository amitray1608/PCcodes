#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll dp[10000][10000];
ll a[10000][10000];
ll rec(int ith,int left,int n,int k){
    if(left == 0 || ith == n)
        return 0;
    if(dp[ith][left] != -1)
        return dp[ith][left];
    ll ans = 0, x=0;
    ans = rec(ith+1, left, n, k);
    for(int i=0; i<left && i<k; i++){
        x = x+a[ith][i];
        ans = max(ans, x+rec(ith+1, left-i-1, n, k));
    }
    return dp[ith][left] = ans;
}
int main(){
    int t;
    cin >> t;
    for(int tt = 1; tt <=t; tt++){
       cout << "Case #" << tt << ": ";
		int n , k, p;
		cin >> n >> k >> p;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < k; j++)
				cin >> a[i][j];
		}
		memset(dp, -1, sizeof dp);
		ll maxi;
		maxi = rec(0, p, n, k);
		//bottom up
		//for(int z = 0; z < p; z++){
			//for(int i = 0; i < n; i++){
				//if(maxi < a[i][dp[i]])
					//maxi = a[i][dp[i]], pos = i;
			//}
			//count += maxi;
			//maxi = -1;
			//if(dp[pos] == k-1)
				//a[pos][dp[pos]] = -1;
			//else
				//dp[pos]++;
		//}
		cout << maxi << endl;
    }
    
}
