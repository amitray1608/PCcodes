#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const int siz = 300000 + 5;
map<char,int> pos;
ll DP[siz];
	set<char>S;
		int len=10000;
void solve()
{
		
		string s;
		cin >> s;
		len = min(len, (int)s.length());
		for(char c:s)
			S.insert(c);
		
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
		cout << S.size() - len +1 ;
	return 0;
}
	
