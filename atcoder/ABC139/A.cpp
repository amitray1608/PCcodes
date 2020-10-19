#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
void solve()
{
		int n;
		cin >> n;
		string s, t;
		cin >> s;
		cin >> t;
		int count = 0;
		if(s[0] == t[0])
		count++;
		if(s[1] == t[1])
		count++;
		if(s[2] == t[2])
		count++;
		
		cout << count;
}

int main()
{
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		ll t = 1;
	//	cin >> t
		while(t--)
		{
			solve();
		}
	return 0;
}
