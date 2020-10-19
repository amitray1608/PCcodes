#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;

void solve()
{
	ll n, m;
	cin >> n >> m;
		vector <ll> dig(11);
		for(int i = 1; i <= 10; i++)
			dig[i] = (m*i)%10;
			
		ll a = n/m, b = a/10, c = a%10;
		ll sum = 0;
		for(int i = 1; i<=c; i++)
			sum += dig[i];
		
		cout << sum + b * accumulate(dig.begin(), dig.end(), 0LL) << endl;
		
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
