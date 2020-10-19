#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const ll siz = 1e6 + 5;
#define deb(x) cout << #x << "x = " << x << endl;

void solve()
{
        ll n, q;
        cin >> n >> q;
        ll a[n] = {0};
        for(ll i=1; i<n; i++)
        {
            cin >> a[i];
            (i&1) ? a[i] = a[i] : a[i] = -1 * a[i];
        }
        
        for(ll i=2; i<n; i++)
            a[i]+=a[i-1];
        
        ll sum = 0, l, r;
        for(ll i=1; i<=q; i++)
        {
            cin >> l >> r;
            
            if(l>r)
               swap(l, r);

			sum = a[r-1]-a[l-1];
            if(~l&1)
				sum = -1*sum;
            
           (~(r-l)&1) ? cout << "UNKNOWN\n" : cout << sum << "\n";
        }
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
	
