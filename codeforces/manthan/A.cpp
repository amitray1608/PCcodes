#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
		ll a, b, n;
		cin >> a >> b >> n;
		ll ans = (a^b);
		if(n%3 == 0)	cout << a << "\n";	
				
		else if(n%3 == 1)	cout << b << "\n";	
			
		else if(n%3 == 2) cout << ans << "\n";	
	
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1;
	cin >> t;
	while(t--)
	{
		solve();
	}
		return 0;
}
