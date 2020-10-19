#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
  ll n;
  cin >> n;
  char str[n][12];
  for(int i=0;i<n;i++)
  {
    cin>>str[i];
    sort(str[i],str[i]+strlen(str[i]));
  }
  ll count=0;
  for(ll i=0;i<n-1;i++)
  {
  	for(ll j=i+1;j<n;j++)
  	{
  		if(strcmp(str[i],str[j])==0)
  			count++;
  	}
  }
  cout<<count;
}
int main()
{
		    ios_base::sync_with_stdio(false);
			cin.tie(NULL);
	int t = 1; 
	//cin >> t;
	while(t--)
	{
		solve();
	}
	return 0;
}
