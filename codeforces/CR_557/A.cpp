#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void solve(){
	ll n, m;
	cin >> n >> m;
	string s[n];
	for(int i = 0; i<n; i++)
		cin >> s[i];
	vector<ll>a(m, 0);
		for(int i = 0; i<m; i++)
			cin >> a[i];
		ll ans = 0;
		for(int i = 0; i<m; i++)
		{
			vector<ll>count(5, 0);
			for(int j = 0; j<n; j++) count[s[j][i] - 'A']++;
			ans += 1LL * a[i] * *max_element(count.begin(), count.end()); 
		}
		cout << ans << endl;
}
 
int main()
{
	
	    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
		ll t =1;
		//	cin >> t;
		while(t--)
		{
			solve();
		}
		return 0;
}
