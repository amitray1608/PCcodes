#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1e9+7;

ll dig(ll x)
{
	ll sum = 0;
		while(x>0){
			sum+=x%10;
			x/=10;
		}
		return sum;
}

void solve(){
		ll n;
		cin >> n;
		ll a[n];
		for(int i = 0; i<n; i++)
			cin >> a[i];
			
			ll sum =INT_MIN;
		
		for(int i = 0; i<n; i++)
			{
				for(int j = 0; j<n; j++)
				{
					if(j!=i)
					{
						ll x = a[i]*a[j];
						ll p = dig(x);
						if(sum < p)
							sum = p;
					}
				}	
			}
			cout << sum << endl;
}

int main(){
		int t;
		cin >> t;
		while(t--)
		{
			solve();
		}
	return 0;
}
