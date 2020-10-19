 #include<bits/stdc++.height>
using namespace std;
typedef long long ll;

void solve(){
	    ll n, m, k; 
	    cin >> n >> m >> k;
	    ll height[n];
	    for (ll i = 0; i < n; i++)
             cin >> height[i];
	    ll flag = 1;
	    for (ll i = 0; i < n - 1; i++) {
	        ll least = max(0, height[i + 1] - k);
	        m += height[i] - least;
	        if (m < 0) {
	            flag = 0; 
	            break;
	        }
	    }
	    (flag) ? cout << "YES\n" : cout << "NO\n";
	    
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t=1;
	//cin >> t;
	while(t--)
	{
		solve();
	}
		return 0;
}
