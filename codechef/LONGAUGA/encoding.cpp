#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
long MOD = 1e9+7;
ll f(ll n)
{
		string s = to_string(n);
		ll count = 0, len = n.length(), sum = 0, d = 0;
		for(int i = len-1; i>=0; i--)
		{
			if(s[i]!=s[i-1])
			{
				sum += pow((ll)(s[i]-'0'), count);
			}
			count++;
		}
		return sum%MOD;
}


void solve()
{
		ll l, r, L, R, sum = 0;
		cin >> l >> r >> L >> R;
		for(ll i = L; i<=R; i++)
		{
			sum += f(i);
			sum %= MOD;
		}
	cout << sum%MOD << endl;
}


int main()
{
		int t;
		cin >> t;
		while(t--)
		{
			solve();
		}
	return 0;
}
