//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const ll siz = 1e6 + 5;
#define deb(x) cout << #x << " = " << x << endl;
#define CALC(a, b) (::sqrt(::pow(a, 2) + ::pow(b, 2))
void solve()
{
	int m, n, c = 0;
	cin >> m >> n;
	for(int i1 = m - 1; i1 > 0; i1--)
	{
		for(int i2 = n - 1; i2 > 0; i2--)
		{
			double t = CALC(i1, i2));
			if(t == (double)((int)t))
			{
				c++;
			}
		}
	}
	cout << c << endl;
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
	
