
    #include <bits/stdc++.h>
using namespace std;
#define test long long int t;cin>>t;while(t--)

int jimtesh(long long int a[100],long long int num)
{
	int n,i=0;
	while(1)
	{
		n=a[i];
		if(n==num)
			break;
		i++;
	}
	return i;
}
int main()
{
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    	long long int count=0;
    	cin>>n;
    	long long w[100],l[n];
    	long long int arr[n];
    	for(int i=0; i<100; i++)
    		w[i]=0;
    	for(long long int i=0; i<n; i++)
    	{
    		cin>>w[i];
    		arr[i]=w[i];
    	} 
    	int osition[n];
    	for(int i=0; i<n; i++)
    			osition[i]=i;
    	for(long long int i=0; i<n; i++)
    	{
    		cin>>l[i];
    	}
    	sort(arr,arr+n);
    	if(n==2)
    	{
    		if(w[0]>w[1])
    		{
    			if(l[0]==1)
    				count=2;
    			else
    				count=1;
    		}
    	}
    	else
    	{
    		for(int j=1; j<n; j++)
    		{
    			int jimtesho=jimtesh(w,arr[j]);
    			int p=osition[jimtesh(w,arr[j-1])];
    			int c=jimtesho;
    			while(c<=p)
    			{
    				c+=l[jimtesho];
    				osition[jimtesho]=c;
    				count++;
    			}
    		}
    	}
    	cout<<count<<"\n";
  }
}
