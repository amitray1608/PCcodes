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
	cin >> n;
	string s;
	cin >> s;
	int count = 0, cnt = 0;
	for(char c : s)
	{
		if(c == 'n')
			{count++;
		}
		
		
			if(c == 'z')
		{	cnt++;}
	}
	
	for(int i = 0; i<count; i++)
		cout << 1 << " ";
		
	for(int i = 0; i<cnt; i++)
		cout << 0 << " ";
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
	
