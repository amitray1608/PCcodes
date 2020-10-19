#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const ll siz = 1e6 + 5;
#define deb(x) cout << #x << " = " << x << endl;

void solve()
{
	string s;
	cin >> s;
	s = "@" + s;
		vector< set <ll> > pos(26);
	for(ll i = 1; i < (ll)s.size(); i++)
		pos[s[i] - 'a'].insert(i);
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
			pos[s[p] - 'a'].erase(p);
			s[p] = c;
			pos[s[p] - 'a'].insert(p);
		} else {
	
			ll l, r;
			cin >> l >> r;
			ll count = 0;
			for(ll c = 0; c <26; ++c)
			{
				auto it = pos[c].lower_bound(l);
				if(it != pos[c].end() && *it <= r) ++count;
			}
			cout << count << endl;
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
	
