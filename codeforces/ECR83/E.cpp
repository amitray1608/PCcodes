#include<bits/stdc++.h>
using namespace std;
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
int main()
{
	   for(int i=0;i<1000;i++)
	   dp[i] = -1;
       cin >> n;
       for(int i=0; i<n; i++)
       	   cin >> a[i];
       for(int i=0; i<n; i++)
		dp[i] = lis(i);
       
       cout << *max_element(dp,dp+n);
	
}
