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
		int n;
		cin >> n;
		int a[n];
		for(int &i:a)
			cin >> i;
		int sum = 0;
		for(int i = 0; i<n-1; i++){
			for(int j = i+1; j<n; j++)
				sum += (a[i] * a[j]);
		}
			
	cout << sum << endl;
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
	
