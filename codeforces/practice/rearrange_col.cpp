#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const ll siz = 1e6 + 5;
#define deb(x) cout << #x << " = " << x << endl;

void solve()
{
	string s[2];
	cin >> s[0];
	cin >> s[1];
	int n = s[0].size();
	int two = 0, up = 0, down = 0, none = 0;
	for(int i = 0; i <n; i++)
	{
		if(s[0][i] == '#' && s[1][i] == '#')
			two++;
		if(s[0][i] == '#' && s[1][i] == '.')
			up++;	
		if(s[0][i] == '.' && s[1][i] == '#')
			down++;
		if(s[0][i] == '.' && s[1][i] == '.')
			none++;
	}
	string a, b;
	if(two == 0 && n != 1)
		cout << "NO\n";
	else
	{
		cout << "YES\n";
		while(up--)
		{
			a += "#";
			b += ".";
		}
		while(two--)
		{
			a += "#";
			b += "#";
		}
		while(down--)
		{
			a += ".";
			b += "#";
		}
		while(none--)
		{
			a += ".";
			b += ".";
		}
		cout << a << endl;
		cout << b << endl;
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
	
