#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){

    ll n;
    cin >> n;
 
    ll a[n];
    for(ll i = 0; i<n; i++)
      cin >> a[i];
 
        ll count=0, temp = 0;
    sort(a, a+n);
    for(ll i=0; i<n; i++)
    {
    	if(a[i]==1 && i ==0 ){
    		temp=1;
    		count++;
    	}
        else if(temp+1 < a[i]){
        temp=a[i]-1;
        count++;
       }
       else if(temp+1==a[i]){
        temp++;
        count++;
       }
       else if(temp==a[i]){
        temp++;
        count++;
       }
}
 
cout << count;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll tst=1;
	//cin >> tst;
	while(tst--)
	{
		solve();
	}
		return 0;
}
 
