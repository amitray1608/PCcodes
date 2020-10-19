#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const ll siz = 1e6 + 5;
#define deb(times) cout << #times << " = " << times << endl;

void solve()
{
	string s;
	cin >> s;
	int n = s.size();
		vector<int>v;
	for(int i = 0; i<n; i++)
		if(s[i] == 'r') v.push_back(i+1);
	for(int i = n-1; i>=0; i--)
		if(s[i] == 'l') v.push_back(i+1);
		
	for(int i : v)
		cout << i << '\n';
	
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
	
