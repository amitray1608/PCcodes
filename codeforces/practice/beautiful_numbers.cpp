#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const int siz = 1e6 + 5;
ll mod = 1e9+7;
#define deb(x) cout << #x << "x = " << x << endl;
ll a, b, n, sum = 0;
bool is_good(ll x)
{
		while(x>0)
		{
			if(x%10 != a && x%10 != b)
				return false;
				
			sum+=x%10;
			x/=10;
		}
		
	return true;
}

bool is_excellent()
{
		if(is_good(sum))
			return true;
		else
			return false;
}

void solve()
{
	cin >> a >> b >> n;
	ll maxi = pow(10, n);
	ll count = 0;
	for(int i = 1; i<=maxi; i++)
	{
		sum = 0;
		if(is_good(i))
		{
			if(is_excellent())
				count = (count+1)%mod;
		}
	}
	cout << count << endl;
}

int main()
{
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		ll t = 1;
	//	cin >> t;
		while(t--)
		{
			solve();
		}
	return 0;
}
	
