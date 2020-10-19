#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const int siz = 1e5 + 5;
ll mod = 1e9+7;
void solve()
{
	string s;
	cin >> s;
	int n = s.length(), flag = 0;
	for(int i = 0; i<n; i++)
	{
		if(s[i] == 'W' && s[i+1] == 'U' && s[i+2] == 'B')
		{	
			if(i!=0&& flag==1)
			cout << " ";
			i = i+2;
		}
		else
		{
			cout << s[i];
			flag = 1;
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
	
