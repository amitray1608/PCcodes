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
	int count = 0;
	int a[n+6];
	a[0] = 1000;
	a[1] = 1000;
	a[2] = 1000;
	a[3] = 1000;
	a[4] = 1000;
	
	for(int  i = 0; i < n ; i++)
		cin >> a[i+5];

    int c = 0;
    for(int i = 0; i < n; i++)
    {
		c = 0;
		for(int j = (i+5)-1; j >= (i+5)-5; j--)
		{
			if(a[i+5] < a[j])
				c++;
		}
		if(c == 5)
			count++;
	}
	cout << count << endl;
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
	
