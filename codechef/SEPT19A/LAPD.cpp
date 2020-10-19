#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const int siz = 1e5 + 5;
ll MOD = 1e9+7;
void solve()
{
        ll a, c, b, temp;
        cin >> a >> b >> c;
        ll all = (((a-1)%MOD) * ((b)%MOD) * ((c-1)%MOD))%MOD;
        ll count = 0, ans = 0;
        for(ll i=1; i<=b; i++)
        {
            for(ll j=1; j+1<=a; j++)
                temp = min(c-1, (i*i)/j),   count = (count +  (temp % MOD))%MOD;
            
            for(ll j=1; j+1<=c ; j++)
            {
                temp = min(a-1, (i*i)/j);
                if(temp > i)
                    count = (count + (temp-i)%MOD)%MOD;   
            }
        }
        ans = (all- (count%MOD)) % MOD; 
        cout << ans << endl;
		
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
	




