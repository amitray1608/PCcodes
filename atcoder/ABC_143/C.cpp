//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const ll siz = 1e6 + 5;
#define deb(x) cout << #x << " = " << x << endl;

void solve()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int count = 1;
	char x = s[0];
	
	for(int i = 1; i<n; i++){
		if(s[i] == x)
			continue;
		else{
			count++;
			x = s[i];
		}
	}
	cout << count << endl;
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
	
