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
	int n = s.length();
	if(s[0] >= 'A' && s[0] <= 'Z')
	{
		if(s[1] >= 'a' && s[1] <= 'z')
		{
			cout << (s[1] - 'a') + 'A';
			for(int i = 1; i<n; i++)
			{
				if(s[i] >= 'A' && s[i] <= 'Z')
				cout << (char)(s[i] - 'A') + 'a';
				
			}
		}
		else 
		{
			for(int i = 0; i<n; i++)
			cout << (char)(s[i] - 'A') + 'a';
		}
		
	}
	else
	cout << s ;
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
	
