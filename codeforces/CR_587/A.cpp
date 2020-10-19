#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const int siz = 1e5 + 5;
#define deb(x) cout << #x << "x = " << x << endl;

void solve()
{
	ll n;
	cin >> n;
	string s;
	cin >> s;
	int count = 0;
	for(int i=0; i<n-1; i+=2)
	{
		if(s[i]==s[i+1])
		{
			s[i]=(s[i]=='b')?'a':'b' ;
			count++;
		}
	}
	cout << count << endl;
	cout << s << endl;
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
	
