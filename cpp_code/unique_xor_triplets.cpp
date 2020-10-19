#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const ll siz = 1e6 + 5;
#define deb(times) cout << #times << " = " << times << endl;

void solve()
{
	int n;
	cin >> n;
	vector <int> a(n);
	int count = 0;
	unordered_set <int> s;
	for(int & i : a)
		cin >> i, s.insert(i);

	for(int i = 0; i < n; i++)
	{
		for(int j = i+1; j<n; j++)
		{
			int xr = a[i]^a[j];
			
			if(s.find(xr) != s.end() && xr != a[i] && xr != a[j])
				count++;
		}
	}
	
	cout << count/3;
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
	
