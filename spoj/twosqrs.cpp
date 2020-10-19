#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const int siz = 1e6 + 5;
#define deb(x) cout << #x << "x = " << x << endl;

void solve()
{
	ll n;
	cin >> n;
	ll j = 0, flag = 0;
	for(ll i = (ll)sqrt(n); i >= 0; )
	{	
		
		if(i*i + j*j == n)
		{	flag = 1;
			break;
		}
		
		if(i*i + j*j < n)
			j++;
		else
			i--;
			

	}
	(flag) ? cout << "Yes\n" : cout << "No\n";
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
	
