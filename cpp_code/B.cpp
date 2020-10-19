#include<bits/stdc++.h>
using namespace std;
int main()
 {
	long long int t;
	cin>>t;
	while(t--)
	{
	    long long int n,i;
	    cin>>n;
	    long long int a[n+1]={0},d[n+1]={0};
	    for(i=0;i<n;i++)
	        cin>>a[i];
	   for(i=0;i<n;i++)
	    cin>>d[i];
	   sort(a,a+n);
	   sort(d,d+n);
	   int p=0,q=0,c=0,max=0;
	   while((p<n)&&(q<n))
	   {
	       if(a[p]<=d[q])
	       {
	           c++;
	           p++;
	           if(c>max)
	            max=c;
	       }
	       
	       else
	       {
	           c--;
	           q++;
	       }
	       
	   }
	   cout<<max<<endl;
	}
	return 0;
}
