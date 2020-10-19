//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define deb(x) cout << #x << " = " << x << endl;
void solve()
{
	int n;
	cin >> n;
	vector<int>v(n);
	for(int &i: v)
		cin >> i;
	
	sort(v.begin(), v.end());
 
	ll flag=0;
	for(int i = 1; i<n; i++)
		if(v[i]-v[i-1]==1) flag=1;
 
	if(flag)
		cout << "2\n";
	else 
		cout << "1\n";
}

int main()
{
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1;
		cin >> t;
		while(t--)
		{
			solve();
		}
	return 0;
}
	
