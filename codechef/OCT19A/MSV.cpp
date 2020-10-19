#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const ll siz = 1e6 + 5;
#define deb(x) cout << #x << " = " << x << endl;

int check_div(ll x)
{
			if(x % 2 != 0)
				return 2;
			if(x % 3 != 0)
				return 3;
			if(x % 3 != 0 && x % 2 != 0)
				return 6;	

	return 0;
}


void solve()
{
	ll n;
	cin >> n;
	vector <ll> a(n);
	
	for(ll & i : a)
		cin >> i;
	
	ll maxi = *max_element(a.begin(), a.end()), maxi_ans = 0;
	int flag = 0;	
	
		ll check[maxi+1] = {0}, times[maxi+1] = {0};
		check[a[n-1]]++;
		for(ll i = n-2; i>=0; i--)
		{
			flag = check_div(a[i]);
			for(ll div = 1; div <= sqrt(a[i]) && div <= maxi; div++)
			{
				if((flag == 2 && div % 2 == 0) || (flag == 3 && div % 3 == 0) || (flag == 6 && div % 6 == 0))
					continue;
				
				if(a[i] % div == 0){
						ll new_d = a[i] / div;
						
						if(check[div] > 0)
							times[div]++, maxi_ans = max(maxi_ans, times[div]);
							
						if(check[new_d] > 0 && new_d != div)
							times[new_d]++, maxi_ans = max(maxi_ans, times[new_d]);
				}
			}
						check[a[i]]++;
		}
			cout << maxi_ans << endl;	
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
	
