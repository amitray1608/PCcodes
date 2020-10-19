#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	ll n;
	cin >> n;
	ll a[n];
	map<ll, ll>c;
		for(ll i = 0; i<n; i++)
	cin >> a[i], c[a[i]]++;
	
	priority_queue< ll, map<ll, ll> , greater<int> >check(c);
	for(auto it = check.begin(); it != check.end(); it++)
		cout << it-> first << " " << it-> second << endl;
		
	ll area = -1;
	
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
