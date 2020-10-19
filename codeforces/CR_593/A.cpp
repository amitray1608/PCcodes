//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const ll siz = 1e6 + 5;
#define deb(x) cout << #x << " = " << x << endl;

void solve()
{
		ll n, m;
        cin >> n >> m;
        ll arr[n];
        for (ll i = 0; i < n; i++) cin >> arr[i];
        ll l = 0, r = 100000, ans = -1;
        while (l < r) {
            //ll mid = l + (r - l) / 2;
            ll tmp = 0;
            for (ll i = 0; i < n; i++) tmp += arr[i] ^ l;
            
            if (tmp <= m) 
            	ans = l;
            	
            l++;
        }
        cout << ans << '\n';
}

int main()
{
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		ll t = 1;
		cin >> t;
		int it = 0;
		while(t--)
		{
		    it++;
		    cout << "Case #" << it << ": ";
			solve();
		}
	return 0;
}
	
