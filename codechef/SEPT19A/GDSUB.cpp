#include<bits/stdc++.h>
using namespace std;
typedef unsigned long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const int siz = 1e5 + 5;
ll p = 1e9+7;

//geeks for geeks power using mod function
unsigned int power(unsigned int x, unsigned int y,  
                                   unsigned int p) 
{ 
    unsigned int res = 1;     
  
    x = x % p;  
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
            
          y = y>>1;  
        x = (x*x) % p; 
    } 
    return res; 
} 

void solve()
{
	ll n, k;
	cin >> n >> k;
	ll a[n];
	for(ll &i : a)
	{
		cin >> i;
	}
	
	ll ans = power(2, n-k, p);
	
	cout  << ans << endl;
	
}

int main()
{
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		ll t = 1;
		//cin >> t;
		while(t--)
		{
			solve();
		}
	return 0;
}
	
