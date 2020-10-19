#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const ll siz = 1e6 + 5;
#define deb(x) cout << #x << "x = " << x << endl;

void solve()
{
	cin.ignore();
	string s;
	getline(cin, s);
	//int freq[26] ={0};
	//map<char, int> mp;
	//cout << s << endl;
	int h = 0, c = 0, a  =0, k=0, e=0, r=0, u=0, p=0, ss = 0;
	for(char x:s)
	{
		if(x =='H')
			h++;
		if(x =='A')
			a++;
		if(x =='C')
			c++;
		if(x =='K')
			k++;
		if(x == 'E')
			e++;
		if(x =='R')
			r++;
		if(x == 'U')
			u++;
		if(x == 'P')
			p++;	
		if(x == ' ')
		ss++;
	}
	
	c /= 2;
		
	//cout << c << endl;
	int lar = min({a, h, c, k, e, r, u, p});
	
	cout << min(ss+1, lar) << endl;
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
	
