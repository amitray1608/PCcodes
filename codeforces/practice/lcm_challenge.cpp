#include<bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef double dd;
const ll INF = 1e18L + 5;
const int siz = 1e6 + 5;
#define deb(x) cout << #x << "x = " << x << endl;
ll lcm(ll, ll, ll);
void solve()
{
	int n;
	cin >> n;
	ll maxi = 0;
	
	/*for(ll i = 1; i <= n; i++)
	{
		for(ll j = 1; j<=n; j++)
		{
			for(ll k = 1; k<=n; k++)
			{
				maxi = max(lcm(i, j, k),maxi);
			}
		}
	}*/
	if(n == 1)
	{	cout << 1 << endl;
		return;
	}
	else if(n == 2)
	{
		cout << 2 << endl;
		return;
	}
	else if(n == 3)
	{
		cout << 6 << endl;
		return;
	}
	else if(n&1)
	{
		maxi = n*(n-1)*(n-2);
	}
	else
	{
		if(n%3==0)
			maxi = (n-1) * (n-2) * (n-3);
		else
			maxi = n * (n-1) * (n-3);
	}
	cout << maxi << endl;
}

ll lcm(ll i, ll j, ll k)
{
		ll a = __gcd(i, j);
		ll al = (i*j / a);
		ll b = __gcd(al, k);
		ll bl = (al*k)/ b;
	
	return bl;
}

int main()
{
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		ll t = 1;
		//cin >> t;
		while(t--)
		{
			//cout << lcm(3, 7, 5) << endl;
			solve();
		}
	return 0;
}
	
