#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const int siz = 1e5 + 5;
#define deb(x) cout << #x << "x = " << x << endl;

void solve()
{
	ll n;
	cin >> n;
	ll a[n];
	for(ll &i : a)
		{cin >> i;}
	
	ll cnt = 1;
	ll v[n] = {0};
	v[n-1] = 0;
	for(int i = n-2; i>=0; i--)
	{
		if(a[i] == a[i+1])
			{v[i] = v[i+1];}
		else
			{v[i] = cnt;}
			
		cnt++;
	}
	
	for(int i = 0; i<n; i++)
		cout << v[i] << " ";
	
	cout << endl;
}

int main()
{
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		ll t = 1;
		cin >> t;
		while(t--)
		{
			solve();
		}
	return 0;
}
	
