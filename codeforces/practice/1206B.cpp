#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	ll n;
	cin >> n;
	ll a[n];
	for(ll i = 0; i<n; i++)
	cin >> a[i];
	ll ans = 0, one = 0, zero = 0, neg = 0;
	for(int i = 0; i<n; i++)
	{
		if(a[i] == 0)
			zero++;
		else if(a[i]==-1)
			neg++;
		else if(a[i]==1)
			one++;
		else
		{
			if(a[i]<0)
				ans += abs(a[i])-1, neg++;
			else
				ans += a[i] - 1;
		}
	}
	if(neg%2)
	{
		if(zero > 0)
			ans+=1, zero--;
			else
			ans += 2;
	}
	
	cout << ans+zero << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1;
	//cin >> t;
	while(t--)
	{
		solve();
	}
		return 0;
}
