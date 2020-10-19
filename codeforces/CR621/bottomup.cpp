#include<iostream>
#include<cstdio>
using namespace std;
int dp[61][10001];
int gcd(int a,int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
int main(void)
{
    int i,j,k,t,n;
    scanf("%d",&t);
    while(t--)
    {
        for(i=1;i<=60;i++)
        {
            for(j=1;j<=10000;j++)
                dp[i][j]=0;
        }
    scanf("%d",&n);
    int arr[n+1];
    for(i=1;i<=n;i++)
        scanf("%d",&arr[i]);
    for(i=1;i<=n;i++)
        dp[i][arr[i]]+=1;
    for(i=2;i<=n;i++)
    {
        for(j=1;j<=10000;j++)
        {
            if(dp[i-1][j]>0)
                dp[i][j]+=dp[i-1][j];
            if(j>=arr[i])
                k=gcd(j,arr[i]);
            else
                k=gcd(arr[i],j);
            dp[i][k]+=dp[i-1][j];
        }
    }
    for( i = 1 ; i < 15; i++){
		for( j = 1; j <15; j++)
			cout << dp[i][j] << " ";
		cout << endl;
	}
    printf("%d\n",dp[n][1]);
    }
    return 0;
}
/*
3
4
2 3 5 7
4
3 4 8 16
3
6 10 15

*/
