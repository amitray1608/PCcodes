#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
		ll n;
		cin >> n;
		ll a[n+1];
		ll b[n], x = 0;
			for(ll i = 0; i<=n; i++)
				cin >> a[i], x+= a[i];
			for(ll i = 0; i<n; i++)
				cin >> b[i];
			ll sum = 0;
		for(ll i = 0 ; i<n; i++)
			{
				if(b[i] >= a[i])
					sum += a[i], b[i] -= a[i], a[i] = 0;
				else if(a[i] > b[i])
				 sum += b[i] , a[i] = a[i] - b[i], b[i] = 0;
				
				if(b[i] >= a[i+1])
				sum += a[i+1], b[i] = b[i] - a[i+1], a[i+1] = 0;
				else if(a[i+1]> b[i])
				 sum +=  b[i], a[i+1] = a[i+1] - b[i], b[i] = 0;
			}
				
				cout << sum << endl;
}
