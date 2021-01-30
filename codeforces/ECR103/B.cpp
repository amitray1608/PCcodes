#include<bits/stdc++.h>

using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) {
    	long long int i,n,k,ans,ans1=0;
    	cin>>n>>k;
    	vector<long long int>a (n);
    	vector<long long int>pre (n);
    	for(i=0;i<n;i++)
    	{
    		cin>>a[i];
    	}
    	pre[0]=a[0];
    	for(i=1;i<n;i++)
    	{
    		ans=(a[i]*100)-(k*pre[i-1]);
    		if(ans<1)
    		{
    			pre[i]=pre[i-1]+a[i];
    		}
    		else
    		{
    			ans1+=ans;
    			pre[i]=pre[i-1]+a[i]+ans;
    		}
    	}
    	cout<<ans1<<"\n";
 
  }
  return 0;
}
