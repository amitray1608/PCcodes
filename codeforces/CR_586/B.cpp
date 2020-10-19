#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const int siz = 1e5 + 5;
#define deb(x) cout << #x << "x = " << x << endl;

void solve()
{
	int n;
	cin>>n;
	ll v[n+1][n+1];
	
	for (int i = 0; i < n; i++) {
	    for (int j = 0; j < n; j++) {
	        cin >> v[i][j];
	    }
	}
	
	for (int i = 0; i < n; i++) {
	    ll tmp = (v[i][(i + 1) % n] * v[i][(i + 2) % n]) / v[(i + 1) % n][(i + 2) % n];
	    cout << sqrt(tmp) << " ";
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
	
