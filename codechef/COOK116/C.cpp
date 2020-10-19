#include <bits/stdc++.h>
using namespace std;
long mod=1e9+7;
long cset(long n)
{
	long c=0;
	while(n)
	{
		c+=(n&1);
		n=n>>1;
	}
	return c;
}
long power(long y)  
{  
    long res = 1,x=2;
    while (y > 0)  
    {
        if (y & 1)  
            res = (res*x) % mod;  
        y = y>>1; 
        x = (x*x) % mod;  
    }  
    return res;  
}  
int main() {
	long t;
	cin>>t;
	while(t--)
	{
		long n,count=0;
		cin>>n;
		vector<long> ar(n);
		for(int i=0;i<n;i++)
		cin>>ar[i];
		for(int i=1;i<n;i++)
		{
			count+=cset(ar[i-1]&ar[i]);
		}
		cout<<power(count)<<"\n";
	}
	return 0;
}
