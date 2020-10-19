#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const ll siz = 1e6 + 5;
#define deb(x) cout << #x << " = " << x << endl;
ll BIT[26][siz], n;

void update(ll * bit, ll ind, int val){
	ind++;
	while(ind <= n){
			bit[ind] += val;
			ind += -ind&ind;
	}
}

ll query(ll *bit, ll ind){
	ll sum = 0;
	while(ind > 0){
		sum  += bit[ind];
		ind -= -ind&ind;
	}
	return sum;
	
}

void solve()
{
	string s;
	cin >> s;
	n = (ll)s.size();

	for(ll i = 0; i < n; i++)
		update(BIT[s[i] - 'a'], i, 1);
		
	ll q;
	cin >> q;
	while(q--)
	{
		ll typo;
		cin >> typo;
		if(typo == 1)
		{
			ll p;
			char c;
			cin >> p >> c;
			p--;
			update(BIT[s[p] - 'a'], p, -1);
			s[p] = c;
			update(BIT[s[p] - 'a'], p, 1);

		} else {
	
			ll ans = 0, l, r, count = 0;
			cin >> l >> r;
			for(ll i = 0; i < 26; i++){
				count = query(BIT[i], r) - query(BIT[i], l-1);
				ans += count > 0;
			}
			
			cout << ans << endl;
		}
	}
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
	
