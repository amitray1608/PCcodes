#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int main()
{
	ll a, b, x, y;
	cin >> a >> b >> x >> y;
	
//	ll x = *min_element(a, a+n);
ll ans = 0;
		for(ll i = 1; i<=a; i++)
		{
			for(ll j = 1; j<=b; j++)
			{
				if(i*y == x*j)
				ans++, cout << "a = " << i << " b = " << j << endl;
			}
		}
			
		
		cout << ans << endl;
		return 0;
}
