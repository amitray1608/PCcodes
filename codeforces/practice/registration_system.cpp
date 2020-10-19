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
	map <string, int> check;
	while(n--)
	{
		string s;
		cin >> s;
		if(check[s] == 0)
			check[s]++, cout << "OK\n";
		else{
			int x = check[s];
			cout << s << x << endl; 
			check[s]++;
		}
	
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
	
