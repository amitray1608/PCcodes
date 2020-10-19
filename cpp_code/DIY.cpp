
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve(){
	ll n;
	cin >> n;
	ll a[n];
	for(int i = 0; i<n; i++)
		cin >> a[i];
	ll count = 0;
	sort(a, a+n);
	ll ma = a[n-2];
	for(ll i = 0; i<n-2; i++)
	{
		if(a[i]<ma)
		count++;
	}
	
	cout << count << endl;
}
 
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1;
	cin >> t;
	while(t--)
	{
		solve();
	}
		return 0;
}
