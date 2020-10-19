#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const int siz = 1e5 + 5;
map<char,int> pos;
map<int,int> vis;
void solve()
{
	ll a, b, c, count=0;
		cin >> a >> b >> c;
		count = (a + b + c)/ 3;
		count = min(count, b);
		count = min(count, a);
		cout << count << "\n";
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
