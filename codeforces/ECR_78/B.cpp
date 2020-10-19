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
	ll n;
	cin >> n;
	for(int i = 0; i < n;i++)
	{
		for(int j = 0; j < n; j++)
		{
			if((i+j)&1)
			cout << 'B';
			
			else 
			cout << 'W';
		}
		cout << "\n";
	}
 
}
 
int main()
{
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		ll t = 1;
	//	cin >> t;
		while(t--)
		{
			solve();
		}
	return 0;
}
